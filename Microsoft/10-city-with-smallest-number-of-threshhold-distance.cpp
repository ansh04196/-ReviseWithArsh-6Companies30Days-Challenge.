class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dst(n, vector<int>(n, INT_MAX));

        // Populate dist array with edge weights
        for (auto it : edges) {
            dst[it[0]][it[1]] = it[2];
            dst[it[1]][it[0]] = it[2];
        }

        // Set diagonal elements to 0
        for (int i = 0; i < n; i++) {
            dst[i][i] = 0;
        }

        // Floyd-Warshall algorithm to find shortest distances
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dst[i][k] == INT_MAX || dst[k][j] == INT_MAX) {
                        continue;
                    }
                    dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
                }
            }
        }

        int minReachableCities = n;
        int cityNo = -1;

        // Count reachable cities for each city
        for (int city = 0; city < n; city++) {
            int count = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (dst[city][adjCity] <= distanceThreshold) {
                    count++;
                }
            }

            // Update cityNo if the current city has fewer reachable cities
            if (count <= minReachableCities) {
                minReachableCities = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};
