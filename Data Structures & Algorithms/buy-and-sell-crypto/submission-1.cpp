class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector <int> min_price;
        int max_profit = 0;

        if (prices.size() == 1)
            return 0;
        
        min_price.push_back(prices[0]);

        for( int i = 1; i < prices.size();i++){
            if ( prices[i] < min_price[i-1])
                min_price.push_back( prices[i] );
            else
                min_price.push_back( min_price[i-1] );
        }

        for (int i = 0 ;i < prices.size();i++){
            int profit = prices[i] - min_price[i];
            if (profit > max_profit)
                max_profit = profit;
        }

        return max_profit;
    }
};

