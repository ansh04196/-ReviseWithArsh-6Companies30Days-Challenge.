class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        const int INF = 999;
        vector<vector<int>> graph(n, vector<int>(n, INF));

        // Initialize graph with edge weights
        for (const auto &edge : edges) {
            int node1 = edge[0] - 1;
            int node2 = edge[1] - 1;
            graph[node1][node2] = graph[node2][node1] = 1;
        }

        // Floyd-Warshall algorithm to find shortest distances
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        vector<int> answer(n - 1, 0);

        // Iterate over all possible subsets of nodes
        for (int subset = 0; subset < (1 << n); subset++) {
            int nodeCount = __builtin_popcount(subset);
            int edgeCount = 0;
            int maxDistance = 0;

            // Iterate over all pairs of nodes in the subset
            for (int i = 0; i < n; i++) {
                if (subset & (1 << i)) {
                    for (int j = i + 1; j < n; j++) {
                        if (subset & (1 << j)) {
                            // Count edges and find max distance within the subset
                            edgeCount += graph[i][j] == 1;
                            maxDistance = max(maxDistance, graph[i][j]);
                        }
                    }
                }
            }

            // Check conditions and update answer vector
            if (edgeCount == nodeCount - 1 && maxDistance > 0) {
                answer[maxDistance - 1]++;
            }
        }

        return answer;
    }
};
