class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if(s[n-1]!='0')return false;//early exit
       
        queue<int>q;
        q.push(0);
        int currMax=0;

        while(!q.empty()){
            int i = q.front();
            q.pop();
            if(i==n-1)return true;
            for(int j =  max(i+minJump,currMax);j<=min(i+maxJump,n-1);j++){
                if(s[j]=='0'){
                    q.push(j);
                }

            }
            currMax=min(i+maxJump+1,n);
        }
        return false;
    }
};