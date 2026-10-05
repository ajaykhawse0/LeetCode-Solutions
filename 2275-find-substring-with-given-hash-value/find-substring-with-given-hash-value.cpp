class Solution {
public:
    int hash(string sub,int power,int mod){
        long long ans = 0;
        long long currPower = 1;

        for(char c:sub){
            int val = (c-'a')+1;

            ans = (ans+(val*currPower)%mod)%mod;

            currPower = (currPower*power)%mod;

        }
return ans%mod;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();

        for(int i=0;i<n-k+1;i++){
            string sub = s.substr(i,k);
            int curr = hash(sub,power,modulo);

            if(curr==hashValue){
                return sub;
            }
        }
        
    return s;}
};