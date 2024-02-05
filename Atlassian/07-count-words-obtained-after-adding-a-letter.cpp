class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int n = targetWords.size();
        map<string, int> m;

        // Step 1: Store sorted strings from targetWords and their frequency in map m
        for (int i = 0; i < n; i++) {
            string sortedStr = targetWords[i];
            sort(sortedStr.begin(), sortedStr.end());
            m[sortedStr]++;
        }

        int ans = 0;

        // Step 2: Iterate through each string in startWords
        for (int i = 0; i < startWords.size(); i++) {
            string tmp = startWords[i];

            // Step 3: For each character in the alphabet, append it to the string if not present
            for (int j = 0; j < 26; j++) {
                char ch = 'a' + j;

                if (find(tmp.begin(), tmp.end(), ch) == tmp.end()) {
                    // Step 4: Create a new string by appending the character
                    string tmp2 = tmp + ch;

                    // Step 5: Sort the new string and check if it exists in the map
                    sort(tmp2.begin(), tmp2.end());

                    if (m.find(tmp2) != m.end()) {
                        // Step 6: Increment the answer by the frequency of the string and remove it from the map
                        ans += m[tmp2];
                        m.erase(tmp2);
                    }
                }
            }
        }

        // Step 7: Return the computed answer
        return ans;
    }
};
