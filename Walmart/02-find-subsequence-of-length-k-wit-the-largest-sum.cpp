class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> elementIdxPairs(n);
        vector<int> resultSeq(k);

        for(int i = 0; i < n; ++i) 
            elementIdxPairs[i] = {nums[i], i};

        sort(rbegin(elementIdxPairs), rend(elementIdxPairs));
        sort(begin(elementIdxPairs), begin(elementIdxPairs) + k, [](auto a, auto b) {
            return a.second < b.second;
        });

        for(int i = 0; i < k; ++i) 
            resultSeq[i] = elementIdxPairs[i].first;

        return resultSeq;
    }
};
