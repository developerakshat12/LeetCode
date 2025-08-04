class Solution {
public:
    int maxVowels(string s, int k) {
        if(!s.size()) return 0;

        int counter = 0;
        for(int i = 0; i < k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ++counter;
        }

        int maxCount = counter;
        int l = 0;
        for(int r = k; r < s.size(); r++){
            if(s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') ++counter;
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') --counter;
            maxCount = max(maxCount , counter);
            l++;
        }
        return maxCount;
    }
};