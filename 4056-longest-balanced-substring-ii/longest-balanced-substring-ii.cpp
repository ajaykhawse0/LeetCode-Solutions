class Solution {
public:
    
    int helper(char ch1, char ch2, string &s) {
        int n = s.size();
        int cnt1 = 0, cnt2 = 0;
        int maxLen = 0;
        
        unordered_map<int,int> mp;
        mp[0] = -1;   // base case
        
        for(int i = 0; i < n; i++) {
            
           
            if(s[i] != ch1 && s[i] != ch2) {
                cnt1 = 0;
                cnt2 = 0;
                mp.clear();
                mp[0] = i;   
                continue;
            }
            
            if(s[i] == ch1) cnt1++;
            else cnt2++;
            
            int diff = cnt1 - cnt2;
            
            if(mp.count(diff)) {
                maxLen = max(maxLen, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        
        return maxLen;
    }
    
    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;
        
        
        // Case 1: Single character
        
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n && s[j] == s[i]) {
                j++;
            }
            maxLen = max(maxLen, j - i);
            i = j;
        }
        
        
        // Case 2: Two characters equal
       
        maxLen = max(maxLen, helper('a','b',s));
        maxLen = max(maxLen, helper('b','c',s));
        maxLen = max(maxLen, helper('a','c',s));
        
        
        // Case 3: Three characters equal
        
        
        int countA = 0, countB = 0, countC = 0;
        unordered_map<string,int> mp;
        mp["0_0"] = -1;  
        
        for(int i = 0; i < n; i++) {
            
            if(s[i] == 'a') countA++;
            else if(s[i] == 'b') countB++;
            else countC++;
            
            int diffAB = countA - countB;
            int diffBC = countB - countC;
            
            string key = to_string(diffAB) + "_" + to_string(diffBC);
            
            if(mp.count(key)) {
                maxLen = max(maxLen, i - mp[key]);
            } else {
                mp[key] = i;
            }
        }
        
        return maxLen;
    }
};