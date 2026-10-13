class Node {
public:
    Node* links[2];

    bool containsKey(int idx) { return (links[idx] != NULL); }
    Node* get(int idx) { return links[idx]; }
    void put(int bit, Node* node) { links[bit] = node; }
};
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }
    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int maximizeXOR(int num) {
        Node* node = root;
        int xr = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                xr = xr | (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return xr;
    }
};
class Solution {
public:
    Trie trie;
    using T = tuple<int,int,int>;
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
         priority_queue<T,vector<T>,greater<T>>pq;
         sort(nums.begin(),nums.end());
         int j = 0;
         for(auto q:queries){
            int val = q[0];
            int limit = q[1];
            pq.push({limit,val,j});
            j++;
         }

         int stored = 0;
         vector<int>ans(queries.size());
         while(!pq.empty()){
            auto[limit,val,i]=pq.top();
            pq.pop();

            while(stored<nums.size()&&nums[stored]<=limit){
                trie.insert(nums[stored]);
                stored++;
            }

            if(stored==0){
                ans[i] = -1;
            }
            else{
                ans[i] = trie.maximizeXOR(val);
            }

         }


 return ans;   }
};