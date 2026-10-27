class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& fuelUsed) {
      //cost can be rewritten as fuel used  
        
        int totalGas = 0;
        int totalUsed = 0;
        int n = gas.size();
        for(int i=0;i<n;i++){
            totalGas += gas[i];
            totalUsed += fuelUsed[i];
        }

        if(totalGas<totalUsed)return -1;


        int surplus = 0;
        int start = 0;

        for(int i=0;i<n;i++){
            surplus += gas[i] - fuelUsed[i];

            if(surplus<0){
                surplus = 0;
                start = i+1;
            }
        }
return start;    }
};