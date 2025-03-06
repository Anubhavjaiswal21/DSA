class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = size(nums);
        bool onepresent = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                onepresent = true;
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        if (onepresent == false)
            return 1;
        nums.push_back(1);

        for (int i = 0; i < n; i++) {
            int ind = abs(nums[i]);
            if (nums[ind] > 0)
                nums[ind] = -1 * nums[ind];
        }

    
        for (int i = 1; i <= n; i++) {
            if (nums[i] > 0)
                return i;
        }
        return n + 1;
    }
};