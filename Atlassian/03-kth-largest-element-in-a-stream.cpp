class KthLargest {
public:
    multiset<int> s;
    int ans;
    int kr;

    KthLargest(int k, vector<int>& nums) {
        for (auto it : nums) {
            s.insert(it);
        }
        kr = k;
    }

    int add(int val) {
        s.insert(val);
        auto it = s.end();
        for (int i = 0; i < kr; i++)
            it--;
        ans = *it;
        return ans;
    }
};