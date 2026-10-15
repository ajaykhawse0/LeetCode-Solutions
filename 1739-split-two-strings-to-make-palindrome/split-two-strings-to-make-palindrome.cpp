class Solution {
public: 
    bool isPal(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }

        return true;
    }
    bool check(string a , string b){
        int i = 0 , j = a.size()-1;
        while(i<j){
            if(a[i]!=b[j]){
              return(isPal(a,i,j) || isPal(b,i,j));
            }
            i++;
            j--;
        }
        return true;
    }
    bool checkPalindromeFormation(string a, string b) {
        return (check(a,b) || check(b,a));
    }
};