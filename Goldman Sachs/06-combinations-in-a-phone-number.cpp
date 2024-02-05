class Solution {
public:
    void generateCombinations(string digits, string currentCombination, int currentIndex, string* digitMapping, vector<string>& result) 
    
    {
        if (currentIndex >= digits.length()) 
        {
            result.push_back(currentCombination);
            return;
        }

        int digitIndex = digits[currentIndex] - '0';
        string mappedValue = digitMapping[digitIndex];

        for (int i = 0; i < mappedValue.length(); i++) 
        {
            currentCombination.push_back(mappedValue[i]);
            generateCombinations(digits, currentCombination, currentIndex + 1, digitMapping, result);
            currentCombination.pop_back();
        }
    }

    
    vector<string> letterCombinations(string digits) 
    {
        vector<string> result;
        if (digits == "") 
        {
            return result;
        }

        string digitMapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string currentCombination = "";
        
        generateCombinations(digits, currentCombination, 0, digitMapping, result);

        return result;
    }
};
