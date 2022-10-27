/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        if(node==NULL) return node;
        Node* clone=new Node(node->val);
        q.push(node);
        mp[node]=clone;
        while(q.empty()==false)
        {
            Node* fr=q.front();
            q.pop();
//             for(auto x: fr -> neighbors) // now travel in adjcant
//             {
//                 if(mp.find(x) == mp.end()) // if not present in map
//                 {
//                     mp[x] = new Node(x -> val, {}); // then create copy
//                     q.push(x); // push nto the queue
                    
							  
											 
//                 }
                
//                 mp[fr] -> neighbors.push_back(mp[x]); // in current node push adjcant node
//             }
            for(auto x: fr->neighbors)
            {
                if(mp.find(x)==mp.end())
                {
                    q.push(x);
                    mp[x] = new Node(x->val);
													
                    
                }
                
                   mp[fr]->neighbors.push_back(mp[x]);
    
				
																						  
            }
        }
//         while(q.empty() == false) // until q. empty == false
//         {
//             Node* curr = q.front(); // extract front node
//             q.pop(); // pop that from queue
            
//             for(auto adj: curr -> neighbors) // now travel in adjcant
//             {
//                 if(mp.find(adj) == mp.end()) // if not present in map
//                 {
//                     mp[adj] = new Node(adj -> val, {}); // then create copy
//                     q.push(adj); // push nto the queue
                    
							  
											 
//                 }
                
//                 mp[curr] -> neighbors.push_back(mp[adj]); // in current node push adjcant node
//             }
//         }
        return mp[node];
        
        
    }
};