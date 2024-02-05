class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        // Vector to store the beautiful indices
        vector<int> beautifulIndices, indicesA, indicesB;
        
        // Lengths of strings
        int lengthS = s.size(), lengthA = a.size(), lengthB = b.size();
        
        // Step 2: Find indices of occurrences of string 'a'
        for (int i = 0; i <= lengthS - lengthA; i++) {
            if (s.substr(i, lengthA) == a) {
                indicesA.push_back(i);
            }
        }
        
        // Step 3: Find indices of occurrences of string 'b'
        for (int j = 0; j <= lengthS - lengthB; j++) {
            if (s.substr(j, lengthB) == b) {
                indicesB.push_back(j);
            }
        }
        
        // Step 4: Check conditions and add beautiful indices to 'beautifulIndices'
        for (int i = 0; i < indicesA.size(); i++) {
            for (int j = 0; j < indicesB.size(); j++) {
                // Check if substrings match and absolute difference <= k
                if (abs(indicesA[i] - indicesB[j]) <= k) {
                    beautifulIndices.push_back(indicesA[i]);
                    break;
                }
            }
        }
        
        // Step 5: Sort the beautiful indices in ascending order
        sort(beautifulIndices.begin(), beautifulIndices.end());
        
        // Step 6: Return the final result
        return beautifulIndices;
    }
};
