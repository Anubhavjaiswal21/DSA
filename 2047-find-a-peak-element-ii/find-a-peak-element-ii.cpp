class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int largest=INT_MIN;
        int first=0,second=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]>largest)
                {
                    largest=mat[i][j];
                    first=i;
                    second=j;
                }
            }
        }
        return {first,second};
    }
};