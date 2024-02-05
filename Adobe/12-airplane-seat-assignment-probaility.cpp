class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        // If there is only one passenger, the probability is 1
        if (n == 1)
            return 1.0;
        // For more than one passenger, the probability is always 1/2
        else
            return 0.5;
    }
};
