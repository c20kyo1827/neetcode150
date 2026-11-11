/*
    State machine
    s0 : initial state; buy -> s1, wait -> s0
    s1 : buy state; sell -> s2, wait -> s1
    s2 : sell state; wait -> s0


    s0 -> s0 | s0 -> s1
    s1 -> s1 | s1 -> s2
    s2 -> s0
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> initial(prices.size(), 0);
        vector<int> buy(prices.size(), 0);
        vector<int> sell(prices.size(), 0);
        initial[0] = 0;
        buy[0] = -prices[0];
        sell[0] = INT_MIN;
        for(int i=1 ; i<prices.size() ; i++) {
            initial[i] = max(initial[i-1], sell[i-1]);
            buy[i] = max(buy[i-1], initial[i-1] - prices[i]);
            sell[i] = buy[i-1] + prices[i];
        }

        return max(initial[prices.size()-1], sell[prices.size()-1]);
    }
};
