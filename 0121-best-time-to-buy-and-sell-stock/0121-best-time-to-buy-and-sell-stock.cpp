class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX; // Track the minimum price seen so far
        int max_profit = 0;       // Track the maximum profit possible
        
        for (int i = 0; i < prices.size(); i++) {
            // If we find a new historical low, update min_price
            if (prices[i] < min_price) {
                min_price = prices[i];
            } 
            // Otherwise, check if selling today yields a better profit
            else if (prices[i] - min_price > max_profit) {
                max_profit = prices[i] - min_price;
            }
        }
        
        return max_profit;
    }
};