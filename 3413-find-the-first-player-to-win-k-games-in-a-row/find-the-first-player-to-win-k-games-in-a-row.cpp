class Solution {
public:typedef pair<int,int>P;
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
          if (k >= n - 1) {
            return max_element(skills.begin(), skills.end()) - skills.begin();
        }
        deque<pair<int,int>>deq;
        for(int i=0;i<n;i++){
            deq.push_back({skills[i],i});
        }

        unordered_map<int,int>freq;

        while(true){
            P first = deq.front();
            deq.pop_front();
            P second = deq.front();
            deq.pop_front();

            if(first.first>second.first){
                deq.push_front(first);
                deq.push_back(second);
                
                freq[first.second]++;
                if(freq[first.second]>=k)return first.second;
            }
            else if(first.first<second.first){
                deq.push_front(second);
                deq.push_back(first);
                
                freq[second.second]++;
                if(freq[second.second]>=k)return second.second;
            }
        }
        
    return -1;}
};