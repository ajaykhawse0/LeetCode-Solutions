// 5. Longest Palindromic Substring
class Solution {
public:
// bool isPalindrome(const string& str) {
//     int left = 0;                  
//     int right = str.length() - 1;   
    
//     while (left < right) {
//         if (str[left] != str[right]) {
//             return false;  
//         }
//         left++;   
//         right--;  //T.L.E
//     }
//     return true;  
// }
string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}
    string longestPalindrome(string s) {
        if(s.size()==1 || s.empty())return s;
        
        string ans="";
        for(int i=0;i<s.size();i++){
         string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.length() > ans.length()) {
            ans = oddPalindrome;
        }

         string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.length() > ans.length()) {
            ans = evenPalindrome;
        }
        
        }
      
   return ans; }
};
//T.C=>O(n*2)
//S.C=>O(
