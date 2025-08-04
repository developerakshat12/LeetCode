class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        if (s.size() == 1) return 1;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); ++right) {
            for (int i = left; i < right; ++i) {
                if (s[i] == s[right]) {
                    // Move left just past the duplicate
                    left = i + 1;
                    break;
                }
            }
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
