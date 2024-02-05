class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        // Step 2: Initialize planet's mass
        long long x = mass;
        
        // Step 3: Iterate through the sorted array
        for(int i = 0; i < arr.size(); i++) {
            // Check if the current asteroid can be destroyed
            if(arr[i] > x) {
                return false; // Planet cannot destroy this asteroid
            }
            
            // Update the planet's mass
            x += arr[i];
        }
        
        // Step 4: If loop completes, return true
        return true;
    }
};
