class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n - 1, ans = 0;
        while (i < n - 1)
        {
            if (nums[i] >= nums[i + 1])
                break;
            i++;
        }
        if (i == n - 1)
            return (n * (n + 1) / 2);
        while (j > 1)
        {
            if (nums[j - 1] >= nums[j])
                break;
            j--;
        }
        ans = i + 2;
        while (j < n)
        {
            int k = i; 
            while (k >= 0 && nums[k] >= nums[j])
                k--;
            ans += (k + 2);
            j++;
        }
        return ans;
    }
};