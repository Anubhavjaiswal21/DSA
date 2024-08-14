class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e8);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
            for (int n : coins)
                if (i - n >= 0)
                    dp[i] = min(dp[i], dp[i - n] + 1);
        return (dp[amount] == 1e8) ? -1 : dp[amount];
    }
};
