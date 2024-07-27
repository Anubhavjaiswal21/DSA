class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftmax=0;
        int total=0;
        int rightmax=0;
        int prefixmax[n];
        int suffixmax[n];

        prefixmax[0]=height[0];
        for(int i=1;i<height.size();i++)
        {
            prefixmax[i]=max(prefixmax[i-1],height[i]);
        }

        suffixmax[n-1]=height[n-1];
        for(int j=n-2;j>=0;j--)
        {
            suffixmax[j]=max(suffixmax[j+1],height[j]);
        }

        for(int i=0;i<n;i++)
        {
            if(height[i]<prefixmax[i] && height[i]<suffixmax[i])
             total+=min(prefixmax[i],suffixmax[i])-height[i];
        }

        return total;  
      
    }
}

;