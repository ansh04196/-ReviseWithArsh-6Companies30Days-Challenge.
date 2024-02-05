class Solution {
public:
    int findTheWinner(int n, int k) {
        if (n == 1) {
            return 1;
        }
        
        // Find the winner index for (n - 1) persons
        int winnerIndex = (k + findTheWinner(n - 1, k) - 1) % n + 1;
        
        return winnerIndex;
    }
};
