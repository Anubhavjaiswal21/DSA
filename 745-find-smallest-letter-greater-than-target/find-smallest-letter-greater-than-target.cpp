class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0;
        int high = n - 1;
        int mid;

        char ans = letters[0];
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};
