class Solution {
public:

// //Approach 1 Backtracling + Recurssion
// void generateBinStr(int n,string s,vector<string>&arr){
//     if(s.size()==n){
//         arr.push_back(s);
//         return ;
//     }
//     generateBinStr(n,s+'0',arr);
//     generateBinStr(n,s+'1',arr);
// }
//     string findDifferentBinaryString(vector<string>& nums) {
//         vector<string>arr;
//         generateBinStr(nums.size(),"",arr);
//         unordered_set<string>st(nums.begin(),nums.end());

//         for(string& str:arr){
//             if(!st.count(str))return str;
//         }

        
// return "000";
//     }

//Approach 2 By using the decimal representation
 string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
     
     unordered_set<int>st;
    for(string&num:nums){
        st.insert(stoi(num,0,2));//this directly converts binary str. to its decimal representation

    }
  string bin = "";
    for(int num=0;num<=n;num++){
        if(!st.count(num)){
           bin = bitset<16>(num).to_string();
            return bin.substr(16-n,n);
        }
    }

 return "0000";}
};