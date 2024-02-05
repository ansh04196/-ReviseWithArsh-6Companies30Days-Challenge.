class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxLength = 0;
        for (int i = 0, left = 0, currentCost = 0; i < s.size(); i++) {
            currentCost += abs(s[i] - t[i]);
            while (currentCost > maxCost) currentCost -= abs(s[left] - t[left++]);
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};
