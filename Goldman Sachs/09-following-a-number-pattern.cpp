class Solution {
public:
    int printMinNumberForPattern(string pattern) {
        vector<char> result;
        stack<char> stack;
        int num = 1;

        for (char c : pattern) {
            stack.push(num + '0');
            num++;

            if (c == 'I') {
                while (!stack.empty()) {
                    result.push_back(stack.top());
                    stack.pop();
                }
            }
        }

        stack.push(num + '0');
        while (!stack.empty()) {
            result.push_back(stack.top());
            stack.pop();
        }

        return stoi(string(result.begin(), result.end()));
    }
};