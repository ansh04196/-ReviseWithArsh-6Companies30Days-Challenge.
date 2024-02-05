class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> qu(nums.begin(), nums.end());
        for(int i=1; i<n; i+=2) {
            nums[i] = qu.top();
            qu.pop();
        }
        for(int i=0; i<n; i+=2) {
            nums[i] = qu.top();
            qu.pop();
        }
    }
};
