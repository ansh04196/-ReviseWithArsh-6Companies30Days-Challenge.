#define MOD int(1e9 + 7)
int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int dp[1001][1025];

class Solution {
public:
    int countSquareFreeSubsets(vector<int> &nums, int index, int bitmask) {
        if (index == nums.size()) {
            return 0;
        }
        if (dp[index][bitmask] != -1) {
            return dp[index][bitmask];
        }

        // "do not take" case
        int doNotTake = countSquareFreeSubsets(nums, index + 1, bitmask) % MOD;

        // "take" case
        int take = 1, newBitmask = bitmask;
        for (int i = 0; i < 10; ++i) {
            if (nums[index] % primeNumbers[i] == 0) {
                if (bitmask & (1 << i)) {
                    take = 0;
                    break;
                }
                newBitmask |= (1 << i);
            }
        }
        if (take == 1) {
            take = (1ll + countSquareFreeSubsets(nums, index + 1, newBitmask)) % MOD;
        }

        return dp[index][bitmask] = (doNotTake + take) % MOD;
    }

    int squareFreeSubsets(vector<int> &nums) {
        memset(dp, -1, sizeof(dp));

        // Remove numbers that are a factor of (primeNumbers[j])^2
        vector<int> filteredNums;
        for (auto num : nums) {
            bool useThisNumber = true;
            for (int j = 0; j < 10; ++j) {
                if (num % (primeNumbers[j] * primeNumbers[j]) == 0) {
                    useThisNumber = false;
                    break;
                }
            }
            if (useThisNumber) {
                filteredNums.push_back(num);
            }
        }

        // Get the answer
        return countSquareFreeSubsets(filteredNums, 0, 0);
    }
};