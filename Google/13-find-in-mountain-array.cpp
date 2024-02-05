class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak, n = mountainArr.length();

        if (n == 1)
            return mountainArr.get(0) == target ? 0 : -1;

        // Binary search to find the peak element
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }
        peak = low;

        // Binary search in the increasing part of the array
        int left = binarySearch(0, peak, mountainArr, target, true);
        if (left != -1)
            return left;

        // Binary search in the decreasing part of the array
        int right = binarySearch(peak + 1, n - 1, mountainArr, target, false);
        return right;
    }

private:
    int binarySearch(int low, int high, MountainArray &arr, int target, bool increasing) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int midValue = arr.get(mid);

            if (midValue == target)
                return mid;
            else if ((increasing && midValue < target) || (!increasing && midValue > target))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // If target is not found
    }
};