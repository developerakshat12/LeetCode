class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // lets think if I was given a large data it would be wise to take it
        // and plot the graph and see the lowest and highest peaks but lets say
        // that array is like this [32 , 1000 , 1 ,2 ,5]
        //  so first we need to find the largest value of the stock and then go
        //  on and find the lowest value before the highest value or we can
        //  think of it as a two pointers

        int minPrice = prices[0]; // Best day to buy so far
        int maxProfit = 0;        // Max profit so far

        for (int i = 1; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxProfit;
    }
};