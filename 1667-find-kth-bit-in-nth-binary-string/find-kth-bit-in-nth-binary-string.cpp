class Solution {
public:
    char findKthBit(int n, int k) {
        string S="0";//S1
        
        for(int i=2;i<=n;i++){
              string inverted="";
              for(int j=0;j<S.size();j++){
                inverted+=((S[j]=='0')?'1':'0');
              }

              reverse(inverted.begin(),inverted.end());

              string newS = S + '1' + inverted;
              S=newS;
        }
  return S[k-1];  }
};