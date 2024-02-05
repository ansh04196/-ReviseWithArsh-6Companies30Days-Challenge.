class Solution {
public:
    vector<int> v;
    vector<vector<int>> rects;
 
    int area(vector<int>& r) {
        return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
    }
    
    Solution(vector<vector<int>> rect) {
        rects = rect;
        int totalArea=0;
        for (auto r: rects) {
            totalArea+=area(r);
            v.push_back(totalArea);
        }
    }
    
    vector<int> pick() {
        
        int rndm = rand() % v.back();
        int indx = upper_bound(v.begin(), v.end(), rndm) - v.begin();
        
        auto r = rects[indx];
        int x = rand() % (r[2] - r[0] + 1) + r[0];
        int y = rand() % (r[3] - r[1] + 1) + r[1];
        return { x, y };
    }
};  