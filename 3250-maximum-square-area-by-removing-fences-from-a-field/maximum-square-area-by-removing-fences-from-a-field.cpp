class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hfences, vector<int>& vfences) {
        int MOD = 1e9+7;
        //add boundary fences
        hfences.push_back(1);
        hfences.push_back(m);
        
        vfences.push_back(1);
        vfences.push_back(n);

        sort(begin(hfences),end(hfences));
        sort(begin(vfences),end(vfences));

        unordered_set<int>widths;

        for(int i=0;i<vfences.size();i++){
            for(int j=i+1 ;j<vfences.size();j++ ){
                int width = vfences[j]-vfences[i];
                widths.insert(width);
            }
        }
          
        int maxSide = 0;

        for(int i=0;i<hfences.size();i++){
        for(int j=i+1;j<hfences.size();j++){
           
           int height = hfences[j]-hfences[i];
           //if same value exist in  width then it will form a square with the height

           if(widths.find(height)!=widths.end()){
            maxSide = max(maxSide,height);
           }
        }}


  return maxSide==0?-1:(1LL * maxSide * maxSide)%MOD;  }
};