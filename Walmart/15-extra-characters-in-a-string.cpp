class Solution {
public:
    int dp[51];
    
    int solve(string& s, unordered_set<string>& dictionary, int i) {
        if (i == s.size()) return 0;

        if (dp[i] != -1) return dp[i];
        
        string currentSubstring = "";
        int minExtra = s.size();
        
        for (int j = i; j < s.size(); j++) {
            currentSubstring += s[j];
            int extraChars = currentSubstring.size();
            
            if (dictionary.count(currentSubstring)) {
                extraChars = 0;
            }
            
            minExtra = min(minExtra, extraChars + solve(s, dictionary, j + 1));
        }
        
        return dp[i] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        unordered_set<string> wordSet(dictionary.begin(), dictionary.end());
        return solve(s, wordSet, 0);
    }
};
