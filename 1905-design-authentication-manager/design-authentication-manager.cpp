class AuthenticationManager {
public:
int ttl ;
unordered_map<string,int>mpp;
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        mpp[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(mpp.find(tokenId) == mpp.end())
            return;

        // Expired token
        if(mpp[tokenId] <= currentTime)
            return;

        // Renew
        mpp[tokenId] = currentTime + ttl;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int cnt=0;
        for(auto&[token,expiration]:mpp){
            // cout<<expiration;
            if(expiration>currentTime){
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */