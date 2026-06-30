class Solution {
public:
    // int numberOfSubstrings(string s) {
    //  //khisakti hue window(sliding window)

    //  int l = 0;
    //  int r = 0;
    //  int n = s.size();
    //  int freq[3]={0};
    //  int ans = 0;

    //  while(r<n){
       
    //    freq[s[r]-'a']++;

    //    while(freq[0]>=1 && freq[1]>=1 && freq[2]>=1){
    //         ans += n-r;
    //         freq[s[l]-'a']--;
    //         l++;
    //    }
    //    r++;
  

    //  }

    // return ans;}
    int numberOfSubstrings(string s) {
    
     int n = s.size();
     int a = -1; 
     int b = -1; 
     int c = -1; 
     int ans = 0;

    for(int i=0;i<n;i++){
        if(s[i]=='a'){
            a = i;
        }
        else if(s[i]=='b'){
            b = i;
        }
        else{
            c = i;
        }

        if(a!=-1 && b!=-1 && c!=-1){
            ans += min({a,b,c})+1;
        }

    }
  

     

    return ans;}
};