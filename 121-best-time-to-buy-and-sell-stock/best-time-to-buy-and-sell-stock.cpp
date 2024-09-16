class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int mini=prices[0];
        int cost=0;
        for(int i=1;i<n;i++)
        {
            cost=prices[i]-mini;
            maxprofit=max(maxprofit,cost);
            mini=min(prices[i],mini);
        }
        return maxprofit;
    }
};