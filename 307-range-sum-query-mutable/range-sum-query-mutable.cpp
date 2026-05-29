class NumArray {
public:
vector<int>arr,prefSum;
    NumArray(vector<int>& nums) {
        arr = nums;
        prefSum.resize(arr.size());
        prefSum[0]=arr[0];
        for(int i=1;i<arr.size();i++){
            prefSum[i]=arr[i]+prefSum[i-1];

        }
        
    }
    
    void update(int index, int val) {
        int prev = arr[index];
        int diff = val-prev;
        arr[index]=val;
        updatePrefSum(index,arr.size(),diff);

    }
    
    int sumRange(int l, int r) {
        if(l==0)return prefSum[r];

        return (prefSum[r]-prefSum[l-1]);
    }
    void updatePrefSum(int l,int r,int val){
        for(int i=l;i<r;i++){
            prefSum[i] += val;

        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(arr);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */