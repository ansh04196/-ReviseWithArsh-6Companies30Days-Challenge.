class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;
        
        if (s.size() < 10) return result;
        
        for (int i = 0; i < s.size() - 9; i++)
            count[s.substr(i, 10)]++;
        
        for (auto a : count)
            if (a.second > 1)
                result.push_back(a.first);
        
        return result;
    }
};
