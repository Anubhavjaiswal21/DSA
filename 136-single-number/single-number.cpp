class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(int i=0;i<nums.size();i++)
        {
            number=number^nums[i];
        }
        return number;
    }
};