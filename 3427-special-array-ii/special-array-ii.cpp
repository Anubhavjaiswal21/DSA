class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
    vector<int> converted(1, 0);
    for(int i = 1; i < nums.size(); ++i) converted.push_back(converted.back() + (nums[i]%2 == nums[i-1]%2));
    for(auto q: queries) ans.push_back( converted[q[0]] == converted[q[1]] );
    return ans;
    }
};