class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string second=strs[n-1];
        int maxi=max(first.size(),second.size());
        for(int i=0;i<maxi;i++)
        {
            if(first[i]==second[i])
            ans.push_back(first[i]);
            else
            break;
        }
        return ans;
    }
};