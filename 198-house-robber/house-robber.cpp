class Solution {
public:
    int solve(int index, vector<int>& dp, vector<int> nums) {
        dp[0] = nums[0];
        int neg = 0;
        int n=nums.size();

        for (int index = 1; index < nums.size(); index++) {
            int pick = nums[index]; 
            if (index > 1)
                pick += dp[index - 2];

            int notpick = 0 + dp[index - 1];
            dp[index] = max(pick, notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n, dp, nums);
    }
};