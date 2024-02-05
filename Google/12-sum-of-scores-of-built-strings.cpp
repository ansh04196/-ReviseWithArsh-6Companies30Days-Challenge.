class Solution {
public:
    long long sumScores(string s) {
        int len = s.size();
        vector<int> prefix_lengths(len);
        int start = 0, end = 0;
        prefix_lengths[0] = len;
        
        for (int current = 1; current < len; ++current) {
            if (current <= end) {
                prefix_lengths[current] = min(end - current + 1, prefix_lengths[current - start]);
            }
            
            while (current + prefix_lengths[current] < len &&
                   s[prefix_lengths[current]] == s[current + prefix_lengths[current]]) {
                prefix_lengths[current]++;
            }
            
            if (current + prefix_lengths[current] - 1 > end) {
                start = current;
                end = current + prefix_lengths[current] - 1;
            }
        }
        
        long long result = 0;
        for (int i = 0; i < len; ++i) {
            result += prefix_lengths[i];
        }
        
        return result;
    }
};
