class Solution {
public:
    const int MOD = 1000000007;

    int calculateBinomialCoefficient(int n, int r) {
        if (r == 0) return 1;

        vector<int> dp(r + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = r; j > 0; j--) {
                dp[j] = ((dp[j] % MOD) + (dp[j - 1] % MOD)) % MOD;
            }
        }

        return dp[r];
    }

    int numberOfWays(int startPos, int endPos, int k) {
        int positionDifference = abs(endPos - startPos);

        if (positionDifference > k || (positionDifference + k) % 2 == 1) {
            return 0;
        }

        int r = (positionDifference + k) / 2;

        return calculateBinomialCoefficient(k, r);
    }
};
