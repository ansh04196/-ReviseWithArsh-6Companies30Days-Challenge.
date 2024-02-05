class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentChildren = 0;
        int i = 0; // index for greed factors
        int j = 0; // index for cookie sizes

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // If the size of the current cookie is enough to satisfy the child's greed factor
                contentChildren++;
                i++; // Move to the next child
            }
            j++; // Move to the next cookie, regardless of whether it's assigned to a child or not
        }

        return contentChildren;
    }
};