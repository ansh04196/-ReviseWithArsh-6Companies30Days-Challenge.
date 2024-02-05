class Solution {
public:
    vector<vector<int>> ans;

    void generateCombinations(int k, int n, vector<int> num, int i, vector<int>& temp) {
        if (n < 0) return;
        if (n == 0) {
            if (temp.size() == k) ans.push_back(temp);
            return;
        }
        if (i == num.size()) return;

        if (num[i] <= n) {
            temp.push_back(num[i]);
            generateCombinations(k, n - num[i], num, i + 1, temp);
            temp.pop_back();
            generateCombinations(k, n, num, i + 1, temp);
        } else {
            generateCombinations(k, n, num, i + 1, temp);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num;
        for (int i = 1; i < 10; i++) {
            num.push_back(i);
        }
        vector<int> temp;
        generateCombinations(k, n, num, 0, temp);
        return ans;
    }
};
