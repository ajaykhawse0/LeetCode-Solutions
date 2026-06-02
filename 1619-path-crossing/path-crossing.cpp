class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<string,bool>visited;

        int x = 0;//initial
        int y = 0;//initial
        string s = to_string(x) + "," + to_string(y);
        visited[s]=true;
        int n = path.size();

        for(int i=0;i<n;i++){
            if(path[i]=='N'){
                y += 1;
                string s = to_string(x) + "," + to_string(y);
                if(visited.count(s))return true;
                visited[s]=true;
            }
           else if(path[i]=='E'){
                x += 1;
                string s = to_string(x) + "," + to_string(y);
                if(visited.count(s))return true;
                visited[s]=true;
            }
           else if(path[i]=='S'){
                y -= 1;
                string s = to_string(x) + "," + to_string(y);
                if(visited.count(s))return true;
                visited[s]=true;
            }
           else if(path[i]=='W'){
                x -= 1;
                string s = to_string(x) + "," + to_string(y);
                if(visited.count(s))return true;
                visited[s]=true;
            }
  
        }


  return false;  }
};