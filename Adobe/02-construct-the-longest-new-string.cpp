class Solution {
public:
    int longestString(int x, int y, int z) 
    {
        // If the counts of "AA" and "BB" are equal, concatenate all strings in alternating order.
        if(x == y)
            return 2 * (x + y + z);
        // If the counts of "AA" and "BB" are not equal, concatenate "AB" strings in between the shorter of the two.
        else
            return 2 * (2 * min(x, y) + 1 + z);
    }
};
