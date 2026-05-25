class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        if(s[n-1]!='0')return false;

        queue<int>q;
        int currMax=0;
        
        q.push(0);
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            if(idx==n-1)return true;
            for(int j=max(idx+minJump,currMax);j<=min(maxJump+idx,n-1);j++){
                if(s[j]=='0')q.push(j);
            }

            currMax = min(n,idx+maxJump+1);


        }
    return false;}
};