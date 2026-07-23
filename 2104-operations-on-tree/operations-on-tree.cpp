class LockingTree {
public:
int n;
vector<int>parent_arr;
unordered_map<int,int>lockMap;

vector< vector<int>> adj_list;
// 1. Traverse Ancestors: O(H) time, O(1) auxiliary space
void getAncestors(int target,vector<int>&ancestors) {
     
    int current = parent_arr[target];
    
    // Trace upward until reaching the root (-1)
    while (current != -1) {
        ancestors.push_back(current);
        current = parent_arr[current];
    }
    
}

// 2. Helper: Convert Parent Array to Adjacency List: O(N) time and space
 void buildAdjacencyList() {
    
    
    for (int node = 0; node < n; ++node) {
        int parent = parent_arr[node];
        if (parent != -1) {
            adj_list[parent].push_back(node);
        }
    }
    
}

// 3. Traverse Descendants using DFS: O(N) time
void getDescendantsDFS(int target,  vector<int>& descendants) {
    for (int child : adj_list[target]) {
        descendants.push_back(child);
        getDescendantsDFS(child, descendants); // Recursive call
    }
}
    LockingTree(vector<int>& parent) {
        parent_arr = parent; 
        n = parent_arr.size();
        adj_list.resize(n);

        buildAdjacencyList();
    }
    
    bool lock(int num, int user) {
        if(lockMap.count(num))return false;
        lockMap[num]=user;
        return true;
            }
    
    bool unlock(int num, int user) {
        if(!lockMap.count(num))return false;

        if(lockMap[num]!=user)return false;
        lockMap.erase(num);

        return true;
            
       
    }
    
    bool upgrade(int num, int user) {
        if(lockMap.count(num))return false;

        vector<int> ancestors;
        getAncestors(num,ancestors);

        for(int anc:ancestors){
            if(lockMap.count(anc))return false;
        }


        vector<int>descendants;
        getDescendantsDFS(num,descendants);
        bool foundOne = false;

        for(int d:descendants){
            if(lockMap.count(d)){
                foundOne = true;
            }
        }

        if(!foundOne)return false;

        //unlocking descendants
        for(int d:descendants){
            if(lockMap.count(d)){
                lockMap.erase(d);
            }
        }

        lockMap[num] = user;
        return true;


    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */