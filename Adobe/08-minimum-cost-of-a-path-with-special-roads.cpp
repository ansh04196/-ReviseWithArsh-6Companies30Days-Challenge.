class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        // Priority queue to store pairs of (cost, index of special road)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Vector to store minimum costs to reach each special road position
        vector<int> minCostToSpecial(specialRoads.size(), 1e9);
        
        // Initial cost without using any special roads
        int totalCost = abs(start[0] - target[0]) + abs(start[1] - target[1]);
        
        // Calculate the cost to reach each special road position from the target position
        for (int i = 0; i < specialRoads.size(); i++) {
            pq.push({abs(specialRoads[i][2] - target[0]) + abs(target[1] - specialRoads[i][3]), i});
        }
        
        // Dijkstra's algorithm
        while (!pq.empty()) {
            int weight = pq.top().first;
            int ind = pq.top().second;
            pq.pop();
            
            if (minCostToSpecial[ind] == 1e9) {
                minCostToSpecial[ind] = min(minCostToSpecial[ind], weight);
                
                // Explore other special roads connected to the current special road
                for (int i = 0; i < specialRoads.size(); i++) {
                    if (ind != i) {
                        pq.push({weight + abs(specialRoads[ind][0] - specialRoads[i][2]) +
                                 abs(specialRoads[ind][1] - specialRoads[i][3]) + specialRoads[ind][4], i});
                    }
                }
            }
        }
        
        // Calculate the final cost by considering each special road
        for (int i = 0; i < specialRoads.size(); i++) {
            totalCost = min(totalCost, abs(specialRoads[i][0] - start[0]) + abs(specialRoads[i][1] - start[1]) +
                                       specialRoads[i][4] + minCostToSpecial[i]);
        }
        
        return totalCost;
    }
};
