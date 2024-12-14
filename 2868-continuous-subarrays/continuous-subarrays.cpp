class Solution {
public:
    long long continuousSubarrays(vector<int>& v) {
        int n=v.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>s;
        priority_queue<pair<int,int>>b;
        long long ans=n;
        int i=0,j=0;
        while(j<n)
        {   
            int i1=i;
            if(i==j)
            {
                s.push({v[i],i});
                b.push({v[i],i});
                j++;
                continue;
            }
            if(abs(v[j]-s.top().first)<=2 && abs(v[j]-b.top().first)<=2)
            {   
                ans=ans+j-i;
                s.push({v[j],j});
                b.push({v[j],j});
                j++;
            }
            else
            {
                while(!s.empty() &&  (abs(s.top().first-v[j])>2 || s.top().second<=i))
                {   
                    i1=max(i1,s.top().second+1);
                    s.pop();
                }
                while(!b.empty() &&  (abs(b.top().first-v[j])>2 || b.top().second<=i))
                {   
                    i1=max(i1,b.top().second+1);
                    b.pop();
                }
                i=i1;
            }
        }
        return ans;
    }
};