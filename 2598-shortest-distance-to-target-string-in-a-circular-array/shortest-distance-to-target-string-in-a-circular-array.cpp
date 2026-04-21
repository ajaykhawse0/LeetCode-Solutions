class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
           int n = words.size();

           int minD = INT_MAX;

           for(int i=0;i<n;i++){
            
            if(words[i]==target){
              
              int diff = abs(i-startIndex);//forward distance

              int dist = min(diff,n-diff);//circular distance

              minD =  min(minD,dist);

            }
           }
   return minD==INT_MAX?-1:minD; }
};