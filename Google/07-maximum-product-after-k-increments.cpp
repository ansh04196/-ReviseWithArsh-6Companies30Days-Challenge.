class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int current;
        int modulo = pow(10, 9) + 7;
        long long int product = 1;

        // Populate min heap with elements from nums
        for (auto &num : nums) {
            minHeap.push(num);
        }

        // Perform k operations
        while (k > 0) {
            current = minHeap.top();
            minHeap.pop();
            minHeap.push(current + 1);
            k--;
        }

        // Calculate product of modified heap elements
        while (!minHeap.empty()) {
            product *= minHeap.top();
            minHeap.pop();
            product %= modulo;
        }

        return product;
    }
};
