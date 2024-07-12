class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            // case1: palindromic string is even
            int leftEven = i - 1;
            int rightEven = i;
            while (leftEven >= 0 && rightEven < n &&
                   s[leftEven] == s[rightEven]) {
                leftEven--;
                rightEven++;
            }
            // calculte the lenght of the current substring
            int lengthEven = rightEven - leftEven - 1;
            if (lengthEven > maxLength) {
                maxLength = lengthEven;
                start = leftEven + 1;
            }

            // case 2: palindromic string is of odd length
            int leftOdd = i - 1;
            int rightOdd = i + 1;
            while (leftOdd >= 0 && rightOdd < n && s[leftOdd] == s[rightOdd]) {
                leftOdd--;
                rightOdd++;
            }
            // calculate the lengh and update
            int lengthOdd = rightOdd - leftOdd - 1;
            if (lengthOdd > maxLength) {
                maxLength = lengthOdd;
                start = leftOdd + 1;
            }
        }
        return s.substr(start, maxLength);
    }
};
