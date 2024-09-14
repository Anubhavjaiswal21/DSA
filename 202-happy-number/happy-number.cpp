class Solution {
public:
  int nextnumber(int n)
  {
    int sum=0;
    int rem=0;
    while(n!=0)
    {
        rem=n%10;
        sum+=rem*rem;
        n=n/10;
    }
    return sum;
  }
    bool isHappy(int n) {
        unordered_set<int> set1;
        while(n!=1 && !set1.count(n))
        {
            set1.insert(n);
            n=nextnumber(n);
        }
        if(n==1)
        return true;
        else
        return false;
    }
};