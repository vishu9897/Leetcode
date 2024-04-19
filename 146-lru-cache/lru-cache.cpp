struct DLL{
    int key;
    int val;
    DLL* next;
    DLL* prev;
    DLL(int k,int v)
    {
        key=k;
        val=v;
    }
};
class LRUCache {
public:
    int cap=0;
    unordered_map<int,DLL*> mp;
    DLL* head;
    DLL* tail;
    LRUCache(int capacity) {
        head= new DLL(-1,-1);
        tail= new DLL(-1,-1);
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    void addNode(DLL *node)
    {
        DLL* tempNode=head->next;
        node->next=tempNode;
        node->prev=head;
        head->next=node;
        tempNode->prev=node;
    }
    void deleteNode(DLL *node)
    {
        DLL* prevNode=node->prev;
        DLL* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        DLL* node=mp[key];
        mp.erase(key);
        int ans= node->val;
        deleteNode(node);
        addNode(node);
            
        
        mp[key]=node;
        return ans;
    }
    
    void put(int key, int value) {
        DLL* newNode= new DLL(key,value);
        if(mp.find(key)!=mp.end())
        {
            DLL* node= mp[key];
            
            deleteNode(node);
            mp.erase(key);

        }
        if(cap<=mp.size()) {
            DLL* temp=tail->prev;
            deleteNode(tail->prev);
            mp.erase(temp->key);
            // free(temp);
        }
        
        addNode(newNode);
        mp[key]=newNode;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */