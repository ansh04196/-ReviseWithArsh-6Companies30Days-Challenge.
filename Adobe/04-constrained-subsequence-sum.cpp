class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = nums;  
        int maxSum = nums[0];   
        priority_queue<pair<int, int>> maxHeap;  
        maxHeap.push({dp[0], 0});

        for (int i = 1; i < n; i++) {
            while (!maxHeap.empty() && maxHeap.top().second < i - k)
                maxHeap.pop();

            dp[i] = max(dp[i], nums[i] + maxHeap.top().first);
            maxHeap.push({dp[i], i});
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};
