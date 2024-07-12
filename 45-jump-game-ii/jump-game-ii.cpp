class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int maxreach = 0, curreach = 0;
        int jumps = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxreach = max(maxreach, nums[i] + i);
            if (i >= curreach) {
                jumps++;
                curreach = maxreach;
            }
            if (curreach >= nums.size() - 1)
                break;
        }
        return jumps;
    }
};
