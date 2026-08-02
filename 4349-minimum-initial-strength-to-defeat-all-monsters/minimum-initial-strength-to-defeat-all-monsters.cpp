class Solution {
public:
    bool canDefeat(long long strength,vector<long long>&bonus,vector<int>& monsters){
        for(int i=0;i<monsters.size();i++){
            if(strength + bonus[i] < monsters[i])return false;

            strength -= monsters[i];

            strength = max(0LL,strength);//strength can't be negative;

            
        }
        return true;
    }
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        //difference array to compute bonuses efficiently
        vector<long long>diff(n+1,0);

        for(int i=0;i<boosts.size();i++){
            int l = boosts[i][0];
            int r = boosts[i][1];
            long long val = boosts[i][2];
            diff[l] += val;//addition
           (r+1 < n) ? diff[r+1] -= val : diff[r+1] -= 0;//reduction such that we can find total bonus in a range
        }

      vector<long long>bonus(n);
        bonus[0] = diff[0];
        for(int i=1;i<n;i++){
            bonus[i] += bonus[i-1] + diff[i];
        }

        //binary search on answers

        long long low = 0;
        long long high = accumulate(monsters.begin(),monsters.end(),0LL);

        while(low<high){
            long long mid = low +(high-low)/2;

            if(canDefeat(mid,bonus,monsters)){
                high = mid;

                
            }
            else{
                low = mid+1;
            }
        }
        
 return low;   }
};