class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n,0);
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = {nums[i],i};
        }
        sort(arr.begin(),arr.end());
        pq.push(arr[0][1]);
        int i=0,j=1;
        while(i<n && j<n){
            if(arr[j][0]-arr[j-1][0] > limit){
                // Up to here, we made one group so arrange these in ans array
                while(!pq.empty()){
                    ans[pq.top()] = arr[i][0];
                    pq.pop();
                    i++;
                }
            }
            pq.push(arr[j][1]);
            j++;
        }

        while(!pq.empty()){
            ans[pq.top()] = arr[i][0];
            pq.pop();
            i++;
        }

        return ans;
    }
};