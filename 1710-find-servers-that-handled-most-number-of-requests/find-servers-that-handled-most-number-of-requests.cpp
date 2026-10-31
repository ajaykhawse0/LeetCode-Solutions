class Solution {
public:using P = pair<int,int>;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        //we have to track free time of each server
        //and also curr free server
        //and time for which the each servers are busy

        vector<int>busyTime(k,0);
        set<int>st;

        for(int i=0;i<k;i++){
            st.insert(i);
        }

        priority_queue<P,vector<P>,greater<P>>pq;

        int n = arrival.size();
        int mx = 0;

        for(int i=0;i<n;i++){
            while(!pq.empty() && arrival[i]>=pq.top().first){
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty())continue;

            int reqServer = i%k;
            auto itrServer =  st.lower_bound(reqServer);
            int avail = -1;
            if(itrServer!=st.end()){
               avail = *itrServer;
            }
            else{
                avail = *st.begin();
            }

            busyTime[avail]++;
            mx = max(mx,busyTime[avail]);
            pq.push({arrival[i]+load[i],avail});
            st.erase(avail);
        }

        vector<int>ans;

        for(int i=0;i<k;i++){
            if(busyTime[i]==mx){
                ans.push_back(i);
            }
        }

        return ans;
    }
};