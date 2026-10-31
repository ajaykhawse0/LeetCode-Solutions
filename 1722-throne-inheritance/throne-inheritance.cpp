class ThroneInheritance {
public:
    string king;
    unordered_map<string,vector<string>>adj;
    unordered_map<string,bool>marGaye;

    void dfs(vector<string>&ans,string curr){
        if(!marGaye[curr]){
            ans.push_back(curr);
        }

        for(auto child:adj[curr]){
            dfs(ans,child);
        }
    }
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
        
    }
    
    void death(string name) {
        marGaye[name] = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(ans,king);

        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */