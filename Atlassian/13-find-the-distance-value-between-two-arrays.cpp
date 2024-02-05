class Solution {
private:
    // Helper function to check if there exists an element in arr within the specified range
    bool isValid(vector<int>& arr, int num, int distance) {
        int low = 0, hi = arr.size() - 1, mid;
        while (low <= hi) {
            mid = (low + hi) / 2;
            if (arr[mid] < num - distance)
                low = mid + 1;
            else if (arr[mid] > num + distance)
                hi = mid - 1;
            else
                return false; // Element within the range found
        }
        return true; // No element within the range found
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Sort arr2 for binary search
        sort(arr2.begin(), arr2.end());
        int distanceValue = 0;
        
        // Iterate through each element in arr1
        for (int i = 0; i < arr1.size(); i++) {
            // Check if there exists any element in arr2 within the specified range
            if (isValid(arr2, arr1[i], d))
                distanceValue++;
        }
        
        return distanceValue;
    }
};
