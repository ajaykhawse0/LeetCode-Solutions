class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(75,0);
        for(char c:s){
            freq[c-'0']++;
        }
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<75;i++){
            if(freq[i]==0)continue;
            pq.push({freq[i],'0'+i});
        }
        
        string result="";
       while(!pq.empty()){
        auto[f,c]=pq.top();
        pq.pop();
        result += string(f,c);
        
       }
        return result;
    }
};