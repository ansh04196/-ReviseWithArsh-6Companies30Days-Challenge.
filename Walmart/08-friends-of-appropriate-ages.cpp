class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
       sort(ages.begin(), ages.end());
        int totalFriendRequests = 0;

        for(int requesterIndex = 0; requesterIndex < ages.size(); requesterIndex++) {
            int requesterAge = ages[requesterIndex];
            int minValidFriendAge = requesterAge / 2 + 7;

            if (requesterAge <= minValidFriendAge)
                continue;

            int lowerBoundIndex = upper_bound(ages.begin(), ages.end(), minValidFriendAge) - ages.begin();
            int upperBoundIndex = upper_bound(ages.begin(), ages.end(), requesterAge) - ages.begin();
            upperBoundIndex--;  
            if (upperBoundIndex >= lowerBoundIndex)
                totalFriendRequests += (upperBoundIndex - lowerBoundIndex);
        }

        return totalFriendRequests;
    }
};
