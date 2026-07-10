class Solution {
public:
    string defangIPaddr(string address) {
        string newAdd = "";
        for(char c:address){
            if(c=='.'){
                newAdd += "[.]";
                continue;}
            
                newAdd += c;
            
        }
        address = move(newAdd);
        return address;
    }
};