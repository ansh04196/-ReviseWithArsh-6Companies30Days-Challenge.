class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        
        // Priority queue to store stones with their combined values in descending order
        priority_queue<pair<int, int>> valueQueue;
        
        for (int i = 0; i < n; i++) {
            valueQueue.push({aliceValues[i] + bobValues[i], i});
        }
        
        int alicePoints = 0, bobPoints = 0, currentPlayer = 0; // currentPlayer = 0 for Alice, 1 for Bob
        
        while (!valueQueue.empty()) {
            pair<int, int> currentStone = valueQueue.top();
            valueQueue.pop();
            
            if (currentPlayer == 0) {
                alicePoints += aliceValues[currentStone.second];
            } else {
                bobPoints += bobValues[currentStone.second];
            }
            
            currentPlayer = currentPlayer ^ 1; // Toggle currentPlayer for the next iteration
        }
        
        if (alicePoints == bobPoints) return 0; // Draw
        else if (alicePoints < bobPoints) return -1; // Bob wins
        else return 1; // Alice wins
    }
};
