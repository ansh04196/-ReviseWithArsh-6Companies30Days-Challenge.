class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int N = nums.size(), mod = 1e9+7, memo[16][(1 << 14)+1]{};
        
        function<int(int, int)> dfs = [&](int last, int mask) {
            if(mask == (1 << N) - 1) return 1;
            if(memo[last+1][mask]) return memo[last+1][mask] - 1;
            
            int result = 0;
            for(int i = 0; i < N; i++) {
                if((mask&(1 << i)) == 0 && (last == -1 || nums[last] % nums[i] == 0 || nums[i] % nums[last] == 0)) {
                    result = (dfs(i, mask | (1 << i)) + result) % mod;
                }
            }
            
            memo[last+1][mask] = result + 1;
            return result;
        };
        
        return dfs(-1, 0);
    }
};
