class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        long long total = accumulate(card.begin(),card.end(),0LL);
        int window = card.size()-k;
        if(window==0)return total;
        long long windowSum = accumulate(card.begin(),card.begin()+window,0LL);

        long long minWindowSum = windowSum;

        for(int i=window;i<card.size();i++){
            windowSum += card[i];
            windowSum -= card[i-window];
            minWindowSum = min(minWindowSum,windowSum);
        }

        return total-minWindowSum;
    }
};