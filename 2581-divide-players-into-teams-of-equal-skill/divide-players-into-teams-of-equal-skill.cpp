class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int l = 0;
        int r = skill.size()-1;
        long long mx = LLONG_MIN;
        long long res = 0;

        while(l<r){
            long long sum = skill[l]+skill[r];
            if(mx==LLONG_MIN)mx = sum;
            else if(mx!=sum)return -1;

            res += (long long)(skill[l]*skill[r]);
            l++;
            r--;
        }
 return res;   }
};