class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int length=nums.size();
        for(int i=0;i<length;i++)
        {
            for(int j=0;j<length;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(nums[i]+nums[j]==target)
                {
                    result.push_back(i);
                }
            }
        }
        return result;
        
    }
};