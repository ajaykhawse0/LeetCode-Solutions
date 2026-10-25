class Solution {
public:
    bool check(vector<int>& position,int limit ,int balls){
        int countBalls = 1;
        int lastPlaced = position[0];

        for(int i=1;i<position.size();i++){
            if(position[i]-lastPlaced >= limit){
                countBalls++;
                lastPlaced = position[i];
            }
             if(countBalls>=balls)return true;
        }
    return countBalls>=balls;}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());

        int low = 0;
        int high = (position[position.size()-1]-position[0])/(m-1);
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;

            if(check(position,mid,m)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid - 1;
            }
        }


    return ans;}
};