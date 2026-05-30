class Solution {
public:
typedef long long ll;
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        ll start = (intLength%2==0)?pow(10,intLength/2-1):pow(10,intLength/2);

        vector<ll>ans;

        for(int q:queries){

            string s = to_string(start+q-1);
            string pal = s;
            reverse(s.begin(),s.end());

            if(intLength%2==0){
                pal+=s;
            }
            else{
                pal += s.substr(1,s.size()-1);
            }

            if(pal.length()==intLength){
                ans.push_back(stoll(pal));
            }
            else{
                ans.push_back(-1);
            }
        }
    return ans;}
};