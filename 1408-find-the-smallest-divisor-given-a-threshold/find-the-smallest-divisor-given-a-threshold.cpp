class Solution {
public:
    int calculateDiv(vector<int>& nums,int divi)
    {
        int divsum=0;
        for(int i=0;i<nums.size();i++)
        {
            divsum+=ceil((double)nums[i]/(double)divi);
        }
        return divsum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
    int maxi=INT_MIN;
    int ans=-1;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,nums[i]);
    }
    int low=1;
    int high=maxi;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(calculateDiv(nums,mid)<=threshold)
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
};