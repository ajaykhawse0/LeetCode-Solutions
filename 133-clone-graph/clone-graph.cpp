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
    Node*dfs(Node*node,unordered_map<Node*,Node*>&mpp){
        vector<Node*>neigh;
        Node*graph = new Node(node->val);
        mpp[node] = graph;

        for(auto &it: node->neighbors ){
           if(mpp.count(it)){
            neigh.push_back(mpp[it]);
           }
           else{
              neigh.push_back(dfs(it,mpp));
           }
        }
        
        graph->neighbors = neigh;

        return graph;

        
    }
    Node* cloneGraph(Node* node) {

      if(node == NULL)return NULL;  
      if(node->neighbors.size()==0){
        Node*graph = new Node(node->val);
        return graph;
      }
     unordered_map<Node*,Node*>mpp;

     return dfs(node,mpp);
    }
};