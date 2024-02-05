class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hBarsCount = 1;
        int vBarsCount = 1;
        int maxHBarsCount = 1;
        int maxVBarsCount = 1;

        // Sort the horizontal bars array
        sort(hBars.begin(), hBars.end());

        // Iterate through horizontal bars to find consecutive count
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == (hBars[i - 1] + 1)) {
                hBarsCount++;
            } else {
                hBarsCount = 1;
            }
            maxHBarsCount = max(maxHBarsCount, hBarsCount);
        }

        // Sort the vertical bars array
        sort(vBars.begin(), vBars.end());

        // Iterate through vertical bars to find consecutive count
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == (vBars[i - 1] + 1)) {
                vBarsCount++;
            } else {
                vBarsCount = 1;
            }
            maxVBarsCount = max(maxVBarsCount, vBarsCount);
        }

        // Choose the minimum of the maximum consecutive counts
        hBarsCount = maxHBarsCount;
        vBarsCount = maxVBarsCount;

        // Calculate the maximum square hole area
        if (hBarsCount == vBarsCount) {
            return (hBarsCount + 1) * (vBarsCount + 1);
        } else if (hBarsCount > vBarsCount) {
            return (vBarsCount + 1) * (vBarsCount + 1);
        } else {
            return (hBarsCount + 1) * (hBarsCount + 1);
        }
    }
};
