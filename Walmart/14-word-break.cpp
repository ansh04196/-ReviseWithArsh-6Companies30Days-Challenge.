class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<bool> dp(n, false);

        for (int i = 0; i < n; ++i) {
            // Check if substring [0:i] is a valid word
            if (dict.find(s.substr(0, i + 1)) != dict.end()) {
                dp[i] = true;
                continue;
            }

            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j + 1, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n - 1];
    }
};
