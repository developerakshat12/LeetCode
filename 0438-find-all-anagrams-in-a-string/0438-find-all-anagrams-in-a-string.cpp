class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        unordered_map<char, int> pMap, sMap;
        vector<int> result;

        // Fill frequency map for string p
        for (char c : p) {
            pMap[c]++;
        }

        int k = p.size();

        // Fill the first window
        for (int i = 0; i < k; ++i) {
            sMap[s[i]]++;
        }

        if (sMap == pMap) result.push_back(0); // First window match

        // Slide the window
        for (int i = k; i < s.size(); ++i) {
            sMap[s[i]]++;             // include new char
            sMap[s[i - k]]--;         // exclude old char
            if (sMap[s[i - k]] == 0)  // clean up zero counts
                sMap.erase(s[i - k]);

            if (sMap == pMap) result.push_back(i - k + 1);
        }

        return result;
    }
};
