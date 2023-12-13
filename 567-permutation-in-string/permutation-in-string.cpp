class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1hash(26,0);
        vector<int> s2hash(26,0);
        int s2len=s2.size();
        int s1len=s1.size();
        if(s1len>s2len)return false;
        for(int i=0;i<s1len;i++)
        {
            s2hash[s2[i]-'a']++;
            s1hash[s1[i]-'a']++;
        }
        if(s1hash==s2hash)
        {
            return true;
        }
        for(int i=s1len;i<s2len;i++)
        {
            s2hash[s2[i]-'a']++;
            s2hash[s2[i-s1len]-'a']--;
            if(s1hash==s2hash)
            {
                return true;
            }
        }
        return false;
    }
};