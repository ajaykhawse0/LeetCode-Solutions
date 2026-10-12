class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        // complete simulation
        set<vector<int>> st;
        for (auto& a : points) {
            st.insert(a);
        }
        if (st.count(target))
            return 0;

        if (points.size() == 1)
            return -1;

        int cnt = 0;
        while (!st.count(target)) {
            cnt++;
            vector<vector<int>> temp;

            for (int i = 0; i < points.size(); i++) {
                for (int j = i+1; j < points.size(); j++) {

                    vector<int>a = points[i];
                    vector<int>b = points[j];

                    if(a==b)continue;

                    int v1 = (a[0]+b[0])/2;
                    int v2 = (a[1]+b[1])/2;
                    int v3 = (a[2]+b[2])/2;

                    vector<int>arr = {v1,v2,v3};

                    if(!st.count(arr)){
                        temp.push_back(arr);
                        st.insert(arr);
                    }
                }
                
            }
            if(temp.size()==0)return -1;

            //insert the new generation points

            for(auto&arr:temp){
                points.push_back(arr);
            }
        }
  return cnt;  }
};