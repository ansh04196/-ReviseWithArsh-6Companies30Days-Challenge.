class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int LCSuff[n + 1][m + 1];
        int result = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;
                else if (nums1[i - 1] == nums2[j - 1]) {
                    LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                    result = max(result, LCSuff[i][j]);
                } else
                    LCSuff[i][j] = 0;
            }
        }
        return result;
    }
};