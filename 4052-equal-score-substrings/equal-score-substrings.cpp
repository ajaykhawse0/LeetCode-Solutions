class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        int pref=0;
        int total=0;
        
        
        for(int i=0;i<n;i++){
            total += ((s[i]-'a')+1); 
        }
        for(int i=0;i<n;i++){
            pref += ((s[i]-'a')+1);
            total -= ((s[i]-'a')+1);
            if(total==pref){
                return true;
            } 
            else if(pref > total)return false;
        }
        
        
return false;
    }
};