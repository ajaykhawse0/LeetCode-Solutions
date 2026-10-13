class Node{
    public:
    Node*links[2];

    bool containsKey(int idx){
        return (links[idx]!=NULL);
    }
    Node*get(int idx){
         return links[idx];
    }
    void put(int bit,Node*node){
        links[bit]=node;
    }
};
class Trie{
public:
     Node*root;
     Trie(){
        root = new Node();
     }
     void insert(int num){
        Node*node = root;

        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;

            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int maximizeXOR(int num){
         Node*node = root;
         int xr = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->containsKey(1-bit)){
                xr = xr|(1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
            }
    return xr;}

};
class Solution {
public:
   
   Trie trie;
   

    int findMaximumXOR(vector<int>& nums) {

        //insert all values
      

         for(int num:nums){
            trie.insert(num);
         }

         int ans = 0;
         //try to maximize answer

         for(int num:nums){
            ans = max(ans,trie.maximizeXOR(num));
         }

        return ans;
    }
};