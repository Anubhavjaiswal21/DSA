class Solution {
public:
    int solve(int index, vector<int> nums) {
        int  prev = nums[0];
        int prev2 = 0;
        int n=nums.size();

        for (int index = 1; index < nums.size(); index++) {
            int pick = nums[index]; 
            if (index > 1)
                pick += prev2;

            int notpick = 0+ prev;
            int curi = max(pick, notpick);
            prev2=prev;
            prev=curi;
 
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
       
        return solve(n, nums);
    }
};