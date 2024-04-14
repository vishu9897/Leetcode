struct Node{
    int val;
    int key;
    Node* next;
    Node* prev;
    int count;
    Node(int ky,int vl)
    {
        key=ky;
        val=vl;
        count=1;
    }
};
struct dll{
    int size;
    Node *head;
    Node *tail;
    dll()
    {
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next= tail;
        tail->prev= head;
        size=0;
    }

    void addFront(Node *node)
    {   
        Node* temp= head->next;
        node->next=temp;
        node->prev=head;
        temp->prev= node;
        head->next= node;
        size++;
    }

    void removeFront(Node *node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;   
        size--;
    }

};
class LFUCache {
    map<int,Node*> keyNode;
    map<int,dll*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize; 
public:
    LFUCache(int capacity) {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;         
    }

    void updateFreqListMap(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->count]->removeFront(node);
        if(node->count == minFreq && freqListMap[node->count]->size ==0)
        {
            minFreq++;
        }

        dll *nextFreqList= new dll();
        if(freqListMap.find(node->count+1) != freqListMap.end())
        {
            nextFreqList= freqListMap[node->count+1];
        }

        node->count +=1;
        nextFreqList->addFront(node);
        freqListMap[node->count]=nextFreqList;
        keyNode[node->key]=node;

    }

    int get(int key) {
        if(keyNode.find(key) != keyNode.end())
        {
            Node* node= keyNode[key];
            int val= node->val;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(maxSizeCache ==0) return;

        if(keyNode.find(key)!=keyNode.end())
        {
            Node* node=keyNode[key];
            node->val= value;
            updateFreqListMap(node);
        }
        else{
            if(curSize==maxSizeCache)
            {
                dll *ls= freqListMap[minFreq];
                keyNode.erase(ls->tail->prev->key);
                ls->removeFront(ls->tail->prev);
                curSize--;
            }
            curSize++;

            minFreq=1;
            dll* listFreq= new dll();
            if(freqListMap.find(minFreq)!=freqListMap.end())
            {
                listFreq= freqListMap[minFreq];
            }      
            
            Node *node = new Node(key,value);
            keyNode[key]=node;
            listFreq->addFront(node);
            
            freqListMap[minFreq]=listFreq;         

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */