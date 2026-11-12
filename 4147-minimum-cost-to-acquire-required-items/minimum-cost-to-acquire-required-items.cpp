class Solution {
public:using ll = long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll c1 = cost1;
        ll c2 = cost2;
        ll n1 = need1;
        ll n2 = need2;
        ll CB = costBoth;
        ll bothNeeded = min(n1,n2);//these pieces are req
        //now we have two options pay by costBoth or c1+c2;

        ll cost = bothNeeded * min(CB,c1+c2);

        n1 -= bothNeeded;
        n2 -= bothNeeded;

        if(n1>0){
            cost += n1 * min(c1,CB);
        }
        else if(n2>0){
            cost += n2 * min(c2,CB);
        }
return cost;
        }
};