class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //sort the products lexographically;

        sort(products.begin(),products.end());

        //use binary search according to search word
        vector<vector<string>>res;
        string prefixWord = "";
        for(char c:searchWord){
        prefixWord += c;

        //apply binary search using lower_bound;
        //it will return an iterator pointing to start of product with prefixWord
        auto it = lower_bound(products.begin(),products.end(),prefixWord);
        
        vector<string>arr;
        for(int i=0;i<3 && it+i != products.end();i++){
              
              string word = *(it+i);//getting the string at the it+i place

              if(word.substr(0,prefixWord.size())==prefixWord){
                arr.push_back(word);
              }

        }
             res.push_back(arr);
        }
  return res;      
    }
};