class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        int repNum,missNum;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++) mp[arr[i]]++;
        
        for(int i=1;i<=n;i++) 
        {
            if(mp[i] == 2) repNum = i;
            if(!mp[i]) missNum = i;
        }
        
        return {repNum,missNum};
    }
};