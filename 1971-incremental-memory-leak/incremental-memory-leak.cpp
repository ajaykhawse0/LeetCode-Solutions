class Solution {
public:
    vector<int> memLeak(int mem1, int mem2) {
        int i = 1;
        while(true){
            if(mem1 < i && mem2 < i)return{i,mem1,mem2};
            if(mem1>=mem2){
                mem1 -= i;
            }
            else{
                mem2 -= i;
            }
            i++;
        }
    return{i,mem1,mem2};}
};