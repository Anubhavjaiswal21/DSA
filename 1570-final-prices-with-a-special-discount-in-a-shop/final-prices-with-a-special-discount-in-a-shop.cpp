class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> minStk;
        int n = prices.size();
        vector<int> discount(n, 0);
        for (int i{n-1}; i>=0; i--) {
            if (!minStk.empty())
                if (minStk.top() <= prices[i])
                    discount[i] = minStk.top();
                else {
                    while (!minStk.empty() && (minStk.top() > prices[i])) minStk.pop();
                    if (!minStk.empty()) discount[i] = minStk.top();
                }
            minStk.push(prices[i]);
        }
        vector<int> selling_price(n);
        for (int i{0}; i<n; i++)
            selling_price[i] = prices[i] - discount[i];
        return selling_price;
    }
};