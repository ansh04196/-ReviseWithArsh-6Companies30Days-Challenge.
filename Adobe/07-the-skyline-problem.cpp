class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> skylinePoints;
        multiset<int> heightSet{0};
        
        vector<pair<int, int>> buildingEdges;
        
        for(auto building: buildings){
            buildingEdges.push_back({building[0], -building[2]});
            buildingEdges.push_back({building[1], building[2]});
        }
        
        sort(buildingEdges.begin(), buildingEdges.end());
        
        int currentHeight = 0;
        
        for(int i = 0; i < buildingEdges.size(); i++){
            int currentEdge = buildingEdges[i].first;
            int heightAtCurrentEdge = buildingEdges[i].second;
            
            if(heightAtCurrentEdge < 0){
                heightSet.insert(-heightAtCurrentEdge);
            } else {
                heightSet.erase(heightSet.find(heightAtCurrentEdge));
            }
            
            auto maxBuildingHeight = *heightSet.rbegin();
            if(currentHeight != maxBuildingHeight){
                currentHeight = maxBuildingHeight;
                skylinePoints.push_back({currentEdge, currentHeight});
            }
        }
        
        return skylinePoints;
    }
};
