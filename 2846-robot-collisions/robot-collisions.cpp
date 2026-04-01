class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();

        vector<int>index(n);
        for(int i=0;i<n;i++){
            index[i] = i;
        }

        sort(index.begin(),index.end(),[&](const int &a,const int &b){
              return positions[a] < positions[b];
        });

       vector<bool>dead(n);

       stack<int>st;

       for(int& idx : index){
        if(directions[idx] == 'R'){
            st.push(idx);
        }

        else{

            while(!st.empty() && (directions[st.top()] == 'R' && healths[idx] > 0)){
                int top = st.top();
                if(healths[idx] < healths[top]){
                    dead[idx] = true;
                  
                     
                    healths[top]--;
                    break;

                }
                
                else if(healths[idx] > healths[top]){
                    dead[top] = true;
                  
                    st.pop();
                    healths[idx]--;
                 

                }

                else{
                 
                     st.pop();
                      dead[top] = true;
                      dead[idx] = true;
                      break;

                }
            }
            if(!dead[idx]){
                st.push(idx);
            }
        }
       }

       vector<int>ans;
       for(int i=0;i<n;i++){
           if(!dead[i]){
            ans.push_back(healths[i]);
           }
       }
return ans;
    }
};