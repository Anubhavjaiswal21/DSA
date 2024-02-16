class Solution {
public:
    int lowerboundbs(vector<int>& nums,int n, int target)
    {
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]>=target)
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
    int upperboundbs(vector<int>& nums,int n, int target)
    {
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]>target)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerboundbs(nums,n,target);
        if((lb==n) || (nums[lb]!=target))
        return {-1,-1};
        return {lb,upperboundbs(nums,n,target)-1};
        
    }
};