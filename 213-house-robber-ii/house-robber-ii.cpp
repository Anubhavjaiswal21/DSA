class Solution {
public:
    int solve(vector<int> nums) {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++) {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;

            int notpick = 0 + prev;
            int curi = max(pick, notpick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        vector<int> temp, temp2;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0) {
                temp.push_back(nums[i]);
            }
            if (i != n - 1) {
                temp2.push_back(nums[i]);
            }
        }
        return max(solve(temp), solve(temp2));
    }
};