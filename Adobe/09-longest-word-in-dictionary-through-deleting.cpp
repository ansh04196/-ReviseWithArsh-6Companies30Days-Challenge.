class Solution {
public:
    bool isSubsequence(string sub, string super) {
        int i = 0;
        int j = 0;
        while (i < sub.size() && j < super.size()) {
            if (sub[i] == super[j])
                i++;
            j++;
        }
        return i == sub.size();
    };

    string findLongestWord(string s, vector<string>& d) {
        string ans = "";
        for (const string& word : d) {
            if (word.size() > ans.size() || (word.size() == ans.size() && word < ans)) {
                if (isSubsequence(word, s))
                    ans = word;
            }
        }
        return ans;
    }
};
