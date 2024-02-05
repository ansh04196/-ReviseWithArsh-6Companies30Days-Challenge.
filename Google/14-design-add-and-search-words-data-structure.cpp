class WordDictionary {
private:
    unordered_map<int, vector<string>> wordMap;

    bool isMatch(string &wordInMap, string &searchWord) {
        int i = 0;
        while (i < wordInMap.size()) {
            if (searchWord[i] != '.' && searchWord[i] != wordInMap[i]) return false;
            i++;
        }

        return true;
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        wordMap[word.size()].push_back(word);
    }

    bool search(string word) {
        if (wordMap.find(word.size()) == wordMap.end()) return false;

        for (auto &wordInMap : wordMap[word.size()]) {
            bool isMatching = isMatch(wordInMap, word);
            if (isMatching) return true;
        }

        return false;
    }
};
