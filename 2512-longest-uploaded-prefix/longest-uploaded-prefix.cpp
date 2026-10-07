class LUPrefix {
public:vector<int>arr;
 int len;
 int pref;
    LUPrefix(int n) {
        len = n;
        arr.assign(n+1,0);
        arr[0]=1;
        pref=0;
    }
    
    void upload(int video) {
        arr[video] = 1;

        while(pref+1<=len && arr[pref+1]==1){
            pref++;
        }
    }
    
    int longest() {
        return pref;}

};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */