class Solution {
public:
int noOfWords(string message){
    stringstream ss(message);
    string word;
    int cnt=0;
    while(ss>>word){
        cnt++;
    }
    return cnt;
}
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        int maxMsg = INT_MIN;
        string ansSender=""; 
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            int msgLen = noOfWords(messages[i]);
            mpp[senders[i]]+=msgLen;

            maxMsg = max(maxMsg,mpp[senders[i]]);
            
     
        }
        cout<<maxMsg;
        for(auto&it:mpp){
            if(it.second==maxMsg){
                if(it.first>ansSender){
                    ansSender=it.first;
                }
            }
        }
    return ansSender;}
};