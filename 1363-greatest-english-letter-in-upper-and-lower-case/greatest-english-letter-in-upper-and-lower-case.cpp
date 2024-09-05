class Solution {
public:
    string greatestLetter(string s) {
        int uc[26] = {0}, lc[26] = {0};
        for (auto i : s) {
            if (i >= 'a' && i <= 'z') {
                lc[i - 'a']++;
            } else if (i >= 'A' && i <= 'Z') {
                uc[i - 'A']++;
            }
        }
        char max = -1;
        for (int i = 0; i < 26; i++) {
            if (uc[i] && lc[i]) {
                if (max < i) {
                    max = i;
                }
            }
        }
        string res = "";
        if (max != -1) {
            res += max + 65;
        }
        return res;
    }
};
