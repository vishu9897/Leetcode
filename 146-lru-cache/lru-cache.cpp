struct Node{
    Node *next;
    Node *prev;
    int key;
    int val;
    Node(int k,int value)
    {   
        // this->next=NULL;
        // this->prev=NULL;
        key=k;
        val=value;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int cap=0;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    

    void deleteNode(Node* node)
    {
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    void addNode(Node* node)
    {
        Node* tempNode= head->next;
        node->next=tempNode;
        node->prev=head;
        
        head->next=node;
        tempNode->prev=node;

    }

    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* node= mp[key];
        mp.erase(key);
        int ans=node->val;
        deleteNode(node);
        addNode(node);

        mp[key]=node;
        return ans;
    }
    
    void put(int key, int value) {
        Node* newNode= new Node(key,value);
        if(mp.find(key)!=mp.end())
        {
            Node* node= mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        if(cap <= mp.size())
        {
            Node* temp=tail->prev;
            deleteNode(tail->prev);
            mp.erase(temp->key);
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