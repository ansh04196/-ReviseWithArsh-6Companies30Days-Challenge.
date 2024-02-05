class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int numRows = img.size();
        int numCols = img[0].size();
        vector<vector<int>> smoothedImage(numRows, vector<int>(numCols, 0));

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                int totalSum = 0;
                int neighborCount = 0;

                for (int x = max(0, i-1); x < min(numRows, i+2); ++x) {
                    for (int y = max(0, j-1); y < min(numCols, j+2); ++y) {
                        totalSum += img[x][y];
                        neighborCount += 1;
                    }
                }

                smoothedImage[i][j] = totalSum / neighborCount;
            }
        }

        return smoothedImage;
    }
};
