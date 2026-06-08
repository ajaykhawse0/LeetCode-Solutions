class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
     vector<int>freq(101,0);
    int x = INT_MAX;
     for(int num:nums){
        freq[num]++;
        x=min(x,num);
     }
     int xFreq = freq[x];
    int y=INT_MAX;
    // int yFreq=0; 
     for(int num:nums){
        if(num != x && xFreq != freq[num]){
           if(num<y){
            y=num;
           }
        }
     }
    if(x==INT_MAX || y==INT_MAX)return {-1,-1};
    return {x,y};    
    }
};