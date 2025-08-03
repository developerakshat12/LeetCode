class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        vector<int> pFreq(26, 0), sFreq(26, 0);
        vector<int> result;

        for (char c : p) pFreq[c - 'a']++;

        int matchCount = 0;
        int windowSize = p.size();

        // Build the initial window
        for (int i = 0; i < windowSize; i++) {
            char c = s[i];
            sFreq[c - 'a']++;
        }

        // Count initial matches
        for (int i = 0; i < 26; i++) {
            if (pFreq[i] == sFreq[i]) matchCount++;
        }

        // Slide the window
        for (int i = windowSize; i < s.size(); i++) {
            if (matchCount == 26) result.push_back(i - windowSize);

            int rightChar = s[i] - 'a';
            int leftChar = s[i - windowSize] - 'a';

            // Add right character
            sFreq[rightChar]++;
            if (sFreq[rightChar] == pFreq[rightChar]) {
                matchCount++;
            } else if (sFreq[rightChar] == pFreq[rightChar] + 1) {
                matchCount--;
            }

            // Remove left character
            sFreq[leftChar]--;
            if (sFreq[leftChar] == pFreq[leftChar]) {
                matchCount++;
            } else if (sFreq[leftChar] == pFreq[leftChar] - 1) {
                matchCount--;
            }
        }

        // Final check for the last window
        if (matchCount == 26) {
            result.push_back(s.size() - windowSize);
        }

        return result;
    }
};
