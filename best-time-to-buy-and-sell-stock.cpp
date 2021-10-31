class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pm = INT_MAX;
        int mr = 0;
        for (int i = 0; i < prices.size(); i++) {
            mr = prices[i] - pm > mr ? prices[i] - pm : mr;
            pm = prices[i] < pm ? prices[i] : pm;
        }
        return mr;
    }
};
