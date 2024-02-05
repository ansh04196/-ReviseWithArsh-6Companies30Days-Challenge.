class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> charFrequencyMap;
        
        for (auto c : s)
            charFrequencyMap[c]++;
        
        vector<pair<int, char>> frequencyCharPairs;
        for (auto it : charFrequencyMap)
            frequencyCharPairs.push_back({it.second, it.first});
        
        sort(frequencyCharPairs.begin(), frequencyCharPairs.end(), [](pair<int, char> a, pair<int, char> b){
            return a.first > b.first;
        });
        
        string result = "";
        for (auto it : frequencyCharPairs)
            result += string(it.first, it.second);
        
        return result;
    }
};
