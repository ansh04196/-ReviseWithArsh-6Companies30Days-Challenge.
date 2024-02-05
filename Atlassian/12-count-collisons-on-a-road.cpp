class Solution {
public:
    int countCollisions(string directions) {
        int totalCollisions = 0, rightCarsCount = 0;
        stack<char> carStack;
        
        for (auto direction : directions) {
            if (direction == 'R') {
                carStack.push('R');
                rightCarsCount++;
            } else if (direction == 'L') {
                if (!carStack.empty() && carStack.top() == 'S') {
                    totalCollisions++;
                } else if (!carStack.empty() && carStack.top() == 'R') {
                    totalCollisions += 2;
                    if (rightCarsCount > 1) totalCollisions += (rightCarsCount - 1);
                    carStack.push('S');
                    rightCarsCount = 0;
                }
            } else {
                if (!carStack.empty() && carStack.top() == 'R') {
                    totalCollisions++;
                    if (rightCarsCount > 1) totalCollisions += (rightCarsCount - 1);
                    carStack.push('S');
                    rightCarsCount = 0;
                }
                carStack.push('S');
            }
        }
        
        return totalCollisions;
    }
};
