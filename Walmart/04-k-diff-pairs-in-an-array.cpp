class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        int l = 0, r = l + 1;
        
        sort(nums.begin(), nums.end());

        while (r < nums.size()) {
            if (abs(nums[r] - nums[l]) == k) {
                ans++;
                l++;
                r++;
                while (r < nums.size() && nums[r] == nums[r - 1])
                    r++;
            } else if (l + 1 != r && abs(nums[r] - nums[l]) > k) {
                l++;
            } else {
                r++;
            }
        }

        return ans;
    }
};
