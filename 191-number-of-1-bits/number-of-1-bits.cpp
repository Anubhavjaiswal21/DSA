class Solution {
public:
    int hammingWeight(int n) {
        int setbits=0;
        while(n>0)
        {
            if(n&1)
            setbits++;
            n=n>>1;
        }
        return setbits;
    }
};