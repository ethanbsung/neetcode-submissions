class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minP = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minP) minP = prices[i];
            maxP = max(maxP, prices[i] - minP);
        }

        return maxP;
    }
};
