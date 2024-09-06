class Solution {
public:
    int myAtoi(string s) {
        bool neg = false;
        int i = 0;
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        while (i < n && s[i] == ' ') {
            i++;
        }
        if (i < n && s[i] == '-') {
            i++;
            neg = true;
        } else if (i < n && s[i] == '+') {
            i++;
        }
        while (i < n && s[i] == '0') {
            i++;
        }
        int j = i;
        for (; i < n; i++) {
            if (!isdigit(s[i])) {
                break;
            }
        }
        if (i == j) {
            return 0;
        }
        if (i - j > 10) {
            if (neg) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        if (i - j == 10) {
            if (neg) {
                string str = "2147483648";
                int k = 0;
                while (k < 10) {
                    if (str[k] == s[j + k]) {
                        k++;
                        if (k == 10) {
                            return INT_MIN;
                        }
                        continue;
                    } else if (s[j + k] > str[k]) {
                        return INT_MIN;
                    } else {
                        break;
                    }
                }
            } else {
                string str = "2147483647";
                int k = 0;
                while (k < 10) {
                    if (str[k] == s[j + k]) {
                        k++;
                        if (k == 10) {
                            return INT_MAX;
                        }
                        continue;
                    } else if (s[j + k] > str[k]) {
                        return INT_MAX;
                    } else {
                        break;
                    }
                }
            }
        }
        string str = s.substr(j, i - j);
        int res = stoi(str);
        if (neg) {
            res = -res;
        }
        return res;
    }
};
