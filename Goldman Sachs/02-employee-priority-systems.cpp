class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> mpp;
        for(auto v: access_times)
            mpp[v[0]].push_back(v[1]);
    
        
        vector<string> ans;
        for(auto p: mpp)
        {
            auto v = p.second;
            auto emply = p.first;

            sort(v.begin(), v.end());
            int n = v.size();

            for(int i = 0; i < n-2; i++)
            {
                if(stoi(v[i+2]) < stoi(v[i])+100)
                {
                    ans.push_back(emply);
                    break;
                }
                    
            }
        }
        return ans;
    }
};