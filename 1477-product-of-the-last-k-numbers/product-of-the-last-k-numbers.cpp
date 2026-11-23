class ProductOfNumbers {
public:
vector<int>prefix;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if(num==0){
            prefix.clear();
            prefix.push_back(1);
        }
        else{
            prefix.push_back(num*prefix.back());
        }
        
    }
    
    int getProduct(int k) {
        int n = prefix.size();
       if(n<=k)return 0;
       else{
    int a = prefix.back()/prefix[n-k-1];
        return a;
       }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */