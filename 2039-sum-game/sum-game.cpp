class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int firstHalf = 0;
        int secondHalf = 0;
        int qinF = 0;
        int qinS = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                qinF++;
            else
                firstHalf += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                qinS++;
            else
                secondHalf += num[i] - '0';
        }

       if(qinF+qinS == 0)return firstHalf!=secondHalf;
       if((qinF + qinS)%2)return true;
       if(qinF == qinS)return firstHalf!=secondHalf;

       return 2*(firstHalf-secondHalf) != 9*(qinS - qinF);
    }
};