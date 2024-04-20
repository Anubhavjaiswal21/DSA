class Solution {
public:
   void findSubsets(int ind,int n,vector<int> &nums,vector<int>&ds,vector<vector<int>> &ans)
   {
    ans.push_back(ds);
    for(int i=ind;i<n;i++)
    {
        if(i!=ind && nums[i]==nums[i-1])
        continue;
        ds.push_back(nums[i]);
        findSubsets(i+1,n,nums,ds,ans);
        ds.pop_back();
    }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> ds;
        findSubsets(0,n,nums,ds,ans);
        return ans;
        
    }
};