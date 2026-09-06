class Solution {
public:
    int solve(string answer,char extra,int k){
        int cnt = 0;
        int ans = 0;
        int l = 0;
        for(int r=0;r<answer.size();r++){
            if(answer[r]==extra)cnt++;

            while(cnt>k){
                if(answer[l]==extra)cnt--;
                l++;
            }

            ans = max(r-l+1,ans);
        }
   return ans; }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey,'F',k),solve(answerKey,'T',k));
    }
};