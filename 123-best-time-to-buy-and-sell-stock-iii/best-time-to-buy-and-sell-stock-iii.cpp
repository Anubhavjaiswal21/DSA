class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // index    //buy or notbuy     //cap
        // 1-buy kar chuka hu
        // 0-buy nhi kra
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int t = 0; t <= 2; t++) {
            dp[0][0][t] = -prices[0]; // kharid liya hai to pehle hi din
            dp[0][1][t] = 0;          // nhi kharida pehle din
        }
        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= 2; t++) {
                
                int sell_ke_baad = dp[i - 1][0][t] + prices[i];
                int bina_sell_kare_aage = dp[i - 1][1][t];
                dp[i][1][t] = max(sell_ke_baad, bina_sell_kare_aage);

                int buy_ke_baad = dp[i - 1][1][t - 1] - prices[i];
                int bina_buy_kare_aage = dp[i - 1][0][t];
                dp[i][0][t] = max(buy_ke_baad, bina_buy_kare_aage);
            }
        }
        return max(dp[n - 1][1][1], dp[n - 1][1][2]);
    }
};
