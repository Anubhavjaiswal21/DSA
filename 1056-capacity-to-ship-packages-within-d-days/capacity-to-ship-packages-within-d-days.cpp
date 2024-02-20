class Solution {
public:
    int leastCapacity(vector<int>& weights, int lcapacity)
    {
        int load=0;
        int countdays=1;
        for(int i=0;i<weights.size();i++)
        {
            if(load+weights[i]>lcapacity)
            {
                countdays+=1;
                load=weights[i];
            }    
            else
            {
                load+=weights[i];
            }
        }
        return countdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi=INT_MIN;
        int ans=-1;
        int weightsum=0;
        for(int i=0;i<weights.size();i++)
        {
            maxi=max(maxi,weights[i]);
            weightsum+=weights[i];
        }
        int low=maxi;
        int high=weightsum;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(leastCapacity(weights,mid)<=days)
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