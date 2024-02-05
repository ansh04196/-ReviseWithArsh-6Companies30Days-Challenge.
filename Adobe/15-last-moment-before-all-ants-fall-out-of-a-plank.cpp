class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // Variable to store the time
       int lastFallMoment = 0;
        
        // Finding the ant which will take the most time to reach the left end
        for(int leftPos: left)
           lastFallMoment = max(lastFallMoment, leftPos);

        // Finding the ant which will take the most time to reach the right end
        for(int rightPos: right)
            lastFallMoment = max(lastFallMoment, n - rightPos);    // (n - r) = the distance from the right end

        return lastFallMoment;
    }
};