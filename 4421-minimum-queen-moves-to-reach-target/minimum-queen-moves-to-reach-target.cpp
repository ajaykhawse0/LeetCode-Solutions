class Solution {
public:
    int minQueenMoves(vector<int>& sr, vector<int>& tr) {

        if(sr==tr)return 0;
        else if(sr[0]==tr[0])return 1;
        else if(sr[1]==tr[1])return 1;
        else if(abs(sr[0]-tr[0])==abs(sr[1]-tr[1]))return 1;

        return 2;
        
    }
};