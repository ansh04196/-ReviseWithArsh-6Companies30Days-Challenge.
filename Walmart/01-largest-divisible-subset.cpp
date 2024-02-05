class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0) {
            return nums;
        }

        // Sort the array
        sort(nums.begin(), nums.end());

        // Initialize variables
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        // Iterate through the array in reverse order
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = 0;
            dp[i][1] = i;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] % nums[i] == 0) {
                    if(dp[j][0] > dp[i][0]) {
                        dp[i][0] = dp[j][0];
                        dp[i][1] = j;
                    }
                }
            }
            dp[i][0]++;
        }

        // Find the index with the maximum length
        int maxIndex = max_element(dp.begin(), dp.end()) - dp.begin();

        // Reconstruct the subset
        vector<int> result;
        int index = maxIndex;
        while(dp[index][1] != index) {
            result.push_back(nums[index]);
            index = dp[index][1];
        }
        result.push_back(nums[index]);

        return result;
    }
};