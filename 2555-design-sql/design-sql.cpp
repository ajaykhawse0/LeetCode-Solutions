class SQL {
public:map<string,int>table;
       unordered_map<string,int>idGiver;
       map<string,set<int>>idAvail;
       map<string,vector<string>>mpp;
    SQL(vector<string>& names, vector<int>& columns) {

        for(int i=0;i<names.size();i++)
        table[names[i]]=columns[i];
    }
    
    bool ins(string name, vector<string> row) {
        if(!table.count(name))return false;
        if(table[name]!=row.size())return false;
        idGiver[name]++;
        int id = idGiver[name];
         string key = name+to_string(id);
         mpp[key] = row;
         idAvail[name].insert(id);
         return true;
    }
    
    void rmv(string name, int rowId) {
         if(!table.count(name))return ;
         string key = name+to_string(rowId);
         if(!mpp.count(key))return ;
         idAvail[name].erase(rowId);
         mpp.erase(key);
    }
    
    string sel(string name, int rowId, int columnId) {
         if(!table.count(name))return "<null>";
         string key = name+to_string(rowId);
         if(!mpp.count(key)|| mpp[key].size()<columnId)return "<null>" ;
         
        return mpp[key][columnId-1];
    }
    
    vector<string> exp(string name) {
        if(!table.count(name))return {};
        vector<string>ans;
        
         
         for(int rowId:idAvail[name]){
             string key = name+to_string(rowId);
             string temp = to_string(rowId);
             
             for(auto&s:mpp[key]){
                temp += ",";
                temp +=s;
             }
             ans.push_back(temp);
             
         }

         return ans;


    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */