class Solution {
public:
    int singleNumber(vector<int>& nums) {
    unordered_map<int,int> m;
    for(auto i:nums){
    m[i]++;
    }
    for(auto val:m){
    if(val.second == 1){
    return val.first;
    }
    }
    return -1;
    }
};