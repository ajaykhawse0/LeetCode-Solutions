class Solution {
public:
    bool checkString(string s) {
        bool hasBBefore = false;
        for(char c:s){
            if(c=='b'){
                hasBBefore = true;
            }
            else if(hasBBefore){
                return false;
            }
        }
    return true;}
};