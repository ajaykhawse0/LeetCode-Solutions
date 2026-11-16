class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long currTime = 0;
        unordered_map<long long ,long long>mpp;

        for(int task:tasks){
            if(!mpp.count(task)){
                mpp[task] = currTime+space+1;
                currTime++;
            }
            else{
                if(mpp[task]>currTime){
                    currTime = mpp[task];
                }
                mpp[task] = currTime+space+1;
                currTime++;
            }
        }
 return currTime;   }
};