class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices&1 || tomatoSlices > 4*cheeseSlices || tomatoSlices < 2*cheeseSlices)return {};

        int J = (tomatoSlices - 2 * cheeseSlices)/2;
        int S = (tomatoSlices - 4*J)/2;

        return {J,S};
        
    }
};