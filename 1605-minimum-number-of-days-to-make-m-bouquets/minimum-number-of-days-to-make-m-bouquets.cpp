class Solution {
public:
    bool possibleday(vector<int>& bloomDay,int day, int m,int k)
    {
        int cnt=0;
        int totalbou=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day)
            {
                cnt++;
            }
            else
            {
                totalbou+=(cnt/k);
                cnt=0;
            }
        }
        totalbou+=(cnt/k);
        return totalbou>=m?true:false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long total=(m*1LL)*(k*1LL);
        if(n<total)
        {
         return -1;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<bloomDay.size();i++)
        {
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possibleday(bloomDay,mid,m,k)==true)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};