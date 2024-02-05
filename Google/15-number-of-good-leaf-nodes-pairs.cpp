class Solution {
public:
    // Helper function to merge distances from left and right subtrees
    void mergeDistances(vector<int> &leftDistances, vector<int> &rightDistances, vector<int> &result, int &distance) {
        int i = 0, j = 0;
        while (i < leftDistances.size() && j < rightDistances.size()) {
            if (leftDistances[i] < rightDistances[j]) {
                if (leftDistances[i] + 1 < distance) {
                    result.push_back(leftDistances[i] + 1);
                }
                i++;
            } else {
                if (rightDistances[j] + 1 < distance) {
                    result.push_back(rightDistances[j] + 1);
                }
                j++;
            }
        }
        while (i < leftDistances.size()) {
            if (leftDistances[i] + 1 < distance) {
                result.push_back(leftDistances[i] + 1);
            }
            i++;
        }
        while (j < rightDistances.size()) {
            if (rightDistances[j] + 1 < distance) {
                result.push_back(rightDistances[j] + 1);
            }
            j++;
        }
    }

    // Helper function to calculate distances from the current node to leaf nodes
    vector<int> countPairsHelper(TreeNode* root, int &distance, int &result) {
        if (root == NULL) {
            return {};
        }
        if (root->left == NULL && root->right == NULL) {
            return {0};
        }

        vector<int> leftDistances = countPairsHelper(root->left, distance, result);
        vector<int> rightDistances = countPairsHelper(root->right, distance, result);

        // Counting good leaf node pairs
        for (int i = 0; i < leftDistances.size() && leftDistances[i] < distance; i++) {
            for (int j = 0; j < rightDistances.size() && rightDistances[j] < distance; j++) {
                if (leftDistances[i] + 1 + rightDistances[j] + 1 <= distance) {
                    result++;
                }
            }
        }

        // Merging distances from left and right subtrees
        vector<int> mergedDistances;
        mergeDistances(leftDistances, rightDistances, mergedDistances, distance);
        return mergedDistances;
    }

    // Main function to count good leaf node pairs
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        countPairsHelper(root, distance, result);
        return result;
    }
};