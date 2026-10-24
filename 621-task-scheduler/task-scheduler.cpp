class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int>freq(26,0);

       int time = 0;//total time

       for(char c:tasks){
           freq[c-'A']++;
       }      

       priority_queue<int>pq;

       for(int i=0;i<26;i++){

        if(freq[i]){
            pq.push(freq[i]);
        }
       }

       while(!pq.empty()){
        int cycle = n+1;
        vector<int>remain;

        while(cycle && !pq.empty()){
            int mx = pq.top();
            pq.pop();

            if(mx>1){
                remain.push_back(mx-1);
            }

            time++;
            cycle--;
            
        }

        for(auto r:remain){
            pq.push(r);
        }
        if(pq.empty())break;
        time += cycle;//idle time 


       }
    return time;}
};