#define mod 1000000007
typedef long long ll;

class Solution {
public:
    ll customPower(ll base, ll exponent) {
        ll result = 1;
        while (exponent) {
            if (exponent % 2 == 1)
                result = (result % mod * base % mod) % mod;
            base = (base % mod * base % mod) % mod;
            exponent = exponent / 2;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        ll maxVal = (1LL << p) - 1; // 2^p - 1
        ll base = (maxVal - 1 + mod) % mod;
        ll exponent = maxVal / 2;

        ll result = (customPower(base, exponent) % mod * (maxVal % mod)) % mod;

        return static_cast<int>(result);
    }
};