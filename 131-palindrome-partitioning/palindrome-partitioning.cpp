class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;

        solve(ans,temp,s,0,s.size());

        return ans;
    }
    void solve(vector<vector<string>>&ans,vector<string>&temp,string s,int idx,int n){
        if(idx==n){
            ans.push_back(temp);
            return;
        }

        for(int j=idx;j<n;j++){
            string slice = s.substr(idx,j-idx+1);

            if(isPalindrome(slice)){
                temp.push_back(slice);
                solve(ans,temp,s,j+1,n);
                //backtrack
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string str){
        int l = 0;
        int r = str.length()-1;

        while(l<r){
            if(str[l] != str[r])return false;
            l++;
            r--;
        }
        return true;
    }
};