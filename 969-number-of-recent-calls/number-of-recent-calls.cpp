class RecentCounter {
public:vector<int>req;
int start;
    RecentCounter() {
        start=0;
    }
    
    int ping(int t) {
        req.push_back(t);
        while(req[start]<t-3000){
            start++;
        }
        return req.size()-start;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */