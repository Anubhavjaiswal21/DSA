class Solution {
public:
    int Solve(vector<int>& nums, int mid)
    {
        int count=1;
        int last=0;
        for(int i=0;i<nums.size();i++)
        {
            if((nums[i]+last)<=mid)
            {
                last+=nums[i];
            }
            else
            {
                count++;
                last=nums[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        int arraysum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
            arraysum+=nums[i];
        }
        int low=maxi;
        int high=arraysum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(Solve(nums,mid)>k)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
            
        }
        return low;
    }
};