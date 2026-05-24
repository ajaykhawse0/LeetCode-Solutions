class Solution {
public:
    int evalute(string ex,int pos1,int pos2){
        int len = ex.length();
       
        int num1=0;
        for(int i=0;i<pos1;i++){
            num1*=10;
            num1+=(ex[i]-'0');
        }
     
        //middlepart
        bool found = false;
        int n1=0,n2=0;
        for(int i = pos1+1;i<pos2;i++){
           if(ex[i]=='+'){
            found=true;
            continue;
           }
           if(!found){
            n1*=10;
            n1+=(ex[i]-'0');
           }
           else{
            n2*=10;
            n2+=(ex[i]-'0');
           }
        }
        
  
        int ans = n1+n2;
        if(num1!=0){
         ans = ans*num1;
        }
  
        int num2=0;
        for(int i=pos2+1;i<len;i++){
            num2*=10;
            num2+=(ex[i]-'0');
        }
      
         if(num2!=0){
         ans = ans*num2;
        }
       
        return ans;
    }
    string minimizeResult(string expression) {
        int n = expression.size();
        int idx = expression.find('+');
        cout<<idx<<endl;
        string ans = "";
        int mn = INT_MAX;

        for(int i=0;i<idx;i++){
            string s = expression;
            s.insert(i,1,'(');
            for(int j = idx+3;j<=n+1;j++){
                string temp =s;
                temp.insert(j,1,')');
                // cout<<"Temp : "<<temp<<endl;
                int val = evalute(temp,i,j);
                if(val<mn){
                    mn=val;
                    ans=temp;
                }
            }
        }


        cout<<mn;
        return ans;
    }
};