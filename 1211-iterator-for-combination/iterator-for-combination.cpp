class CombinationIterator {
public:int n;
        string s;
        set<string>st;
        // auto curr;
        set<string>::iterator curr;
        void generate(int i,string &comb){
              if(comb.size()==n){
                st.insert(comb);
                return;
              }

              for(int j=i;j<s.size();j++){
                comb += s[j];
                generate(j+1,comb);
                comb.pop_back(); 
              }
        }
    CombinationIterator(string characters, int combinationLength) {
           s = characters;
           n = combinationLength;
           string comb;
           generate(0,comb);
           curr = begin(st);
    }


    
    string next() {
        return *curr++;
    }

    
    bool hasNext() {
     return   curr!=st.end();  
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */