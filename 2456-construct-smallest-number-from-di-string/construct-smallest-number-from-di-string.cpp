class Solution {
public:
    string smallestNumber(string pattern) {
        string s = "";
        stack<char> stk;
        for (int i = 0; i <= pattern.size(); ++i) {
            stk.push((char)('0' + i + 1));
            for (; !stk.empty() && (i == pattern.size() || pattern[i] == 'I');
                 stk.pop())
                s += stk.top();
        }
        return s;
    }
};

