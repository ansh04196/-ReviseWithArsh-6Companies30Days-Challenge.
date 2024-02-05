class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, int> wordOccurrences;
        int totalLength = 0;

        sort(words.begin(), words.end(), compareLength);

        for (const string& word : words) {
            wordOccurrences[word]++;
        }

        for (const string& word : words) {
            int wordLength = word.size();
            if (wordOccurrences[word] > 0) {
                totalLength += (wordLength + 1);
            }

            for (int j = wordLength - 1; j >= 0; j--) {
                string suffix = word.substr(j, wordLength - j);
                wordOccurrences[suffix] = 0;
            }
        }
        return totalLength;
    }

private:
    static bool compareLength(const string& first, const string& second) {
        return first.size() > second.size();
    }
};
