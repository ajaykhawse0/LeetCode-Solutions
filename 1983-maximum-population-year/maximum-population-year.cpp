class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
       map<int,int>Line;
       int ansYear = 0;
       int maxPopulation = 0;
       
        for(auto&log:logs){
            int birthYear = log[0]; 
            int deathYear = log[1];
            Line[birthYear]++;
            Line[deathYear]--;
            
        }
int population=0;
        for(auto& i : Line){
            population += i.second;
            int year =i.first ;
            
            if(population>maxPopulation){
                maxPopulation = population;
                ansYear = year;
            }
        }

    return ansYear;}
};