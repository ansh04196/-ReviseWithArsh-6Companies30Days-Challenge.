class Solution {
private:
    const int mod = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> persons(n + 1, 0);
        persons[1] = 1;

        long long totalSharing = 0;

        for (int i = 2; i <= n; ++i) {
            if (i - delay >= 0) 
                totalSharing = (totalSharing + persons[i - delay]) % mod;
            if (i - forget >= 0) 
                totalSharing = (totalSharing - persons[i - forget] + mod) % mod;

            persons[i] = totalSharing;
        }

        long long ans = 0;

        for (int i = n - forget + 1; i <= n; ++i) {
            ans = (ans + persons[i]) % mod;
        }

        return static_cast<int>(ans);
    }
};
