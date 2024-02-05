class Solution {
public:
    int maxSubarrayLength(vector<int>& array, int maxFrequency) {
        int size = array.size();
        int count = 0, maxLength = 0, windowStart = 0, windowEnd = 0;
        unordered_map<int, int> frequencyMap;
        
        while (windowEnd < size) {
            frequencyMap[array[windowEnd++]] += 1;
            
            // Adjust the window if the frequency constraint is violated
            while (frequencyMap[array[windowEnd - 1]] > maxFrequency) {
                frequencyMap[array[windowStart++]] -= 1;
            }
            
            // Update the maximum length of the good subarray
            maxLength = max(maxLength, windowEnd - windowStart);
        }
        
        return maxLength;
    }
};
