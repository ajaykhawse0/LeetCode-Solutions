class Solution {
public:
int solve(string &s1,string &s2){

    //making s2 strictly greater than s2; 
    int ans = INT_MAX;

    for(char c = 'a' ; c<'z';c++){
        
        int changes = 0;
        for(char i : s1) changes += i > c;
        for(char i : s2) changes += i <= c;

        ans = min(changes,ans);
    }
return ans;}
    int minCharacters(string a, string b) {
        
        int ans = INT_MAX;
        //try first condition
         ans = min(ans,solve(a,b));
        //try second condition
        ans = min(ans,solve(b,a));

        //try third condition

        for(char c = 'a';c<='z';c++){

        int changes = 0;
        for(char i : a) changes += i != c;
        for(char i : b) changes += i != c;

        ans = min(ans,changes);
        
        }
    return ans;}

    //T.C => O(26*(a+b)) => O(a+b)
    //Auxillary Space => O(1);
};