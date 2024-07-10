class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int maxnum = arr[0];

        for (int i = 1; i < n; i++) {
            maxnum = max(maxnum, arr[i]);
        }

        if (maxnum <= 0) {
            return maxnum;
        }

        vector<int> left(n), right(n);

        int bestmax = 0, currmax = 0;

        for (int i = 0; i < n; i++) {
            currmax = max(
                arr[i],
                currmax + arr[i]); 
            bestmax = max(bestmax, currmax);
            left[i] = currmax;
        }
        currmax = 0;
        for (int i = n - 1; i >= 0; i--) {
            currmax = max(arr[i], currmax + arr[i]);
            bestmax = max(bestmax, currmax);
            right[i] = currmax;
        }

        int ans = bestmax;

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }

        return ans;
    }
};