class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        //bfss
        queue<int>q;

        int ans = 0;

        q.push(start);

        vector<bool>vis(1001,false);

        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int curr = q.front();
                
                q.pop();

                if(curr==goal)return ans;
                
                if(curr<0 || curr>1000 || vis[curr])continue;
                
                
                vis[curr] = true;
                

                for(int i=0;i<nums.size();i++){
                    int x = curr + nums[i];
                    int y = curr - nums[i];
                    int z = curr ^ nums[i];

                    q.push(x);
                    q.push(y);
                    q.push(z);
                }
            }
            ans++;
            
        }
return -1;    }
};
