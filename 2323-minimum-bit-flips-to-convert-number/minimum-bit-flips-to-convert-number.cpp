class Solution {
public:
    int minBitFlips(int start, int goal) {
     int count=0;
    int ans=start^goal;
    int cnt=0;
    while(ans){
    int rsb=ans&(-ans);
    ans=ans-rsb;
    cnt++;
    }
    return cnt;
    }
};