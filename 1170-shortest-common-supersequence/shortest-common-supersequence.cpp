class Solution {
public:
    vector<vector<int>> lcs(string& s1, string& s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));

        for (int idx = 0; idx < s1.size() + 1; idx++)
            dp[idx][0] = 0;

        for (int idx = 0; idx < s2.size() + 1; idx++)
            dp[0][idx] = 0;

        for (int row = 1; row < s1.size() + 1; row++) {
            for (int col = 1; col < s2.size() + 1; col++) {
                if (s1[row - 1] == s2[col - 1])
                    dp[row][col] = 1 + dp[row - 1][col - 1];

                else
                    dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
            }
        }

        return dp;
    }

    string shortestCommonSupersequence(string& str1, string& str2) {
        vector<vector<int>> dp = lcs(str1, str2);

        int idx1 = str1.size(), idx2 = str2.size();
        string ans = "";

        while (idx1 > 0 and idx2 > 0) {
            if (str1[idx1 - 1] == str2[idx2 - 1]) {
                ans.push_back(str1[idx1 - 1]);
                idx1--;
                idx2--;
            }

            else {
                if (dp[idx1 - 1][idx2] > dp[idx1][idx2 - 1]) {
                    ans.push_back(str1[idx1 - 1]);
                    idx1--;
                } else {
                    ans.push_back(str2[idx2 - 1]);
                    idx2--;
                }
            }
        }

        while (idx1 != 0) {
            ans.push_back(str1[idx1 - 1]);
            idx1--;
        }

        while (idx2 != 0) {
            ans.push_back(str2[idx2 - 1]);
            idx2--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
