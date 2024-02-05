class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for (const string& word : words) {
            mp[word]++;
        }

        vector<pair<string, int>> freqVector(mp.begin(), mp.end());

        sort(freqVector.begin(), freqVector.end(), [&](const auto& a, const auto& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });

        vector<string> result;

        for (int i = 0; i < k && i < freqVector.size(); ++i) {
            result.push_back(freqVector[i].first);
        }

        return result;
    }
};