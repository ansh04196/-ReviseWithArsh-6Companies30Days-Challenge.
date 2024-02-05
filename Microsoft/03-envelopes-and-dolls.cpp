class Solution {
    static bool cmpr(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), cmpr);

        vector<int> vldenv;
        for(auto e : envelopes) {
            if(!vldenv.size() || vldenv.back() < e[1]) vldenv.push_back(e[1]);
            else {
                int pos = lower_bound(vldenv.begin(), vldenv.end(), e[1]) - vldenv.begin();
                vldenv[pos] = e[1];
            }
        }
        return vldenv.size();
    }
};