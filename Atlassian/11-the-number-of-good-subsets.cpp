class Solution {
private:
    int mod = 1e9 + 7;
    unordered_map<int, int> primeIndexMap;
    unordered_map<int, vector<int>> primeDivisorMap;
    unordered_set<int> badNumbers;
    int dp[31][1 << 10];
    int n;

    // Binary exponentiation
    long long power(long long base, int exponent) {
        long long result = 1;
        base = base % mod;
        if (base == 0) return 0;

        while (exponent > 0) {
            if (exponent & 1)
                result = (result * base) % mod;
            exponent = exponent >> 1;
            base = (base * base) % mod;
        }

        return result % mod;
    }

    // Calculate the number of good subsets
    long long calculateGoodSubsets(vector<int>& frequency, int currentIndex, int bitmask) {
        // Base case
        if (currentIndex == 31) {
            if (bitmask) return 1;
            else return 0;
        }

        // Base case
        if (dp[currentIndex][bitmask] != -1) return dp[currentIndex][bitmask];

        // Calling recursion
        if (frequency[currentIndex] == 0 || badNumbers.count(currentIndex) > 0) {
            return dp[currentIndex][bitmask] = calculateGoodSubsets(frequency, currentIndex + 1, bitmask);
        }
        else if (primeIndexMap.find(currentIndex) != primeIndexMap.end()) {
            if (bitmask & (1 << primeIndexMap[currentIndex]))
                return dp[currentIndex][bitmask] = calculateGoodSubsets(frequency, currentIndex + 1, bitmask);
            else {
                long long take = frequency[currentIndex] * calculateGoodSubsets(frequency, currentIndex + 1, bitmask | (1 << primeIndexMap[currentIndex]));
                long long notTake = calculateGoodSubsets(frequency, currentIndex + 1, bitmask);
                return dp[currentIndex][bitmask] = (take + notTake) % mod;
            }
        }
        else {
            bool flag = true;
            int newMask = bitmask;
            for (int prime : primeDivisorMap[currentIndex]) {
                newMask |= (1 << primeIndexMap[prime]);
                if (bitmask & (1 << primeIndexMap[prime])) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                long long take = frequency[currentIndex] * calculateGoodSubsets(frequency, currentIndex + 1, newMask);
                long long notTake = calculateGoodSubsets(frequency, currentIndex + 1, bitmask);
                return dp[currentIndex][bitmask] = (take + notTake) % mod;
            }
            else {
                return dp[currentIndex][bitmask] = calculateGoodSubsets(frequency, currentIndex + 1, bitmask);
            }
        }
    }

public:
    int numberOfGoodSubsets(vector<int>& nums) {
        // Using dynamic programming with bitmasking
        memset(dp, -1, sizeof(dp));

        // Storing prime numbers with indices
        primeIndexMap[2] = 0; 
        primeIndexMap[3] = 1; 
        primeIndexMap[5] = 2; 
        primeIndexMap[7] = 3; 
        primeIndexMap[11] = 4;
        primeIndexMap[13] = 5; 
        primeIndexMap[17] = 6; 
        primeIndexMap[19] = 7; 
        primeIndexMap[23] = 8; 
        primeIndexMap[29] = 9;

        primeDivisorMap[6] = {2, 3};
        primeDivisorMap[10] = {2, 5}; 
        primeDivisorMap[14] = {2, 7}; 
        primeDivisorMap[15] = {3, 5};
        primeDivisorMap[21] = {3, 7}; 
        primeDivisorMap[22] = {2, 11}; 
        primeDivisorMap[26] = {2, 13}; 
        primeDivisorMap[30] = {2, 3, 5};

        badNumbers.insert({1, 4, 8, 9, 12, 16, 18, 20, 24, 25, 27, 28});

        // Find the count of every element in the array
        vector<int> frequency(31, 0);
        for (int num : nums) frequency[num]++;

        // Calculate the result
        int result = (power(2, frequency[1]) * calculateGoodSubsets(frequency, 2, 0)) % mod;

        return result;
    }
};

