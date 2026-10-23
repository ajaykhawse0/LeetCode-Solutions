class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if(password.size()<8)return false;
         if (!regex_search(password, regex("(?=.*[0-9])")) ||
            !regex_search(password, regex("(?=.*[a-z])")) ||
            !regex_search(password, regex("(?=.*[A-Z])")) ||
            !regex_search(password, regex("(?=.*[!@#$%^&*()\\-+])")))return false;
        
        
        int n = password.size();

        for(int i=1;i<n;i++){
            if(password[i]==password[i-1])return false;
        }
    return true;}
};