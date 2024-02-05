class Solution {
public:
    bool isValidSerialization(string preorder) {
        
        vector<string> tokens;
        stringstream tokenStream(preorder);
        string currentToken;
        while (getline(tokenStream, currentToken, ',')) {
            tokens.push_back(currentToken);
        }
        
        int availableSlots = 1; 
        for (auto token : tokens) {
            availableSlots--;
            if (availableSlots < 0) {
                return false;
            }
            if (token != "#") {
                availableSlots += 2;
            }
        }
        return availableSlots == 0;
    }
};
