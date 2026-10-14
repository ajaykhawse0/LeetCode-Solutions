class Solution {
public: bool isBlack(string s){
    char c = s[0];
    char row = s[1];

    if(row == '1' || row == '3' || row == '5' || row == '7'){
        return (c=='a' || c=='c' || c=='e' || c=='g');
    }
    else{
        return (c=='b' || c=='d' || c=='f' || c=='h');
    }
}
public: bool isWhite(string s){
    char c= s[0];
    char row = s[1];

    if(row == '2' || row == '4' || row == '6' || row == '8'){
        return (c=='a' || c=='c' || c=='e' || c=='g');
    }
    else{
        return (c=='b' || c=='d' || c=='f' || c=='h');
    }
}
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        if(isBlack(coordinate1) && isBlack(coordinate2))return true;
        if(isWhite(coordinate1) && isWhite(coordinate2))return true;
    return false;}
};