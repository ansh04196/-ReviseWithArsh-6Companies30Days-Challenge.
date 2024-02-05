class Solution {
public:
    string getHint(string secret, string guess) {
        int srt_size = secret.size();
        int bulls = 0;
        string hint = "";

        // Step 1: Find bulls
        for (int i = 0; i < srt_size; i++)
            if (secret[i] == guess[i]) {
                secret[i] = guess[i] = 'o';
                bulls++;
            }
        
        // Format the bulls count
        hint += to_string(bulls);
        hint.push_back('A');

        // Step 2: Count cows using unordered map
        unordered_map<char, pair<int, int>> char_count;
        for (int i = 0; i < srt_size; i++) {
            // Count occurrences of each digit in secret and guess
            char_count[secret[i]].first++;
            char_count[guess[i]].second++;
        }
        // Remove 'o' from consideration
        char_count.erase('o');

        int cows = 0;
        // Step 3: Iterate through unordered map to find cows
        for (auto [theChar, theCount] : char_count)
            cows += min(theCount.first, theCount.second);
        
        // Format the cows count
        hint += to_string(cows);
        hint.push_back('B');

        return hint;
    }
};
