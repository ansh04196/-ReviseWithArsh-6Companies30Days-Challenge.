class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) 
    {
        int rows = isWater.size();
        int cols = isWater[0].size();
        vector<vector<int>> heights(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++){
                if(isWater[i][j] == 1){
                    q.push({i, j});
                    heights[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();
            int dx[4] = {0, 0, -1, 1};
            int dy[4] = {-1, 1, 0, 0};
            
            for(int i = 0; i < 4; i++){
                int nextRow = currentRow + dx[i];
                int nextCol = currentCol + dy[i];
                
                if(nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && heights[nextRow][nextCol] > 1 + heights[currentRow][currentCol]){
                    heights[nextRow][nextCol] = 1 + heights[currentRow][currentCol];
                    q.push({nextRow, nextCol});
                }
            }
        }
        return heights;
    }
};