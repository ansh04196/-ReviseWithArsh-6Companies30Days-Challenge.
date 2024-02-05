class Solution {
public:
    map<vector<int>,int>mp;
    int m,n;
    
    Solution(int m, int n) 
    {
        this->m=m;
        this->n=n;
    }
    
    vector<int> flip()
    {
        int m1=rand()%m;
        int n1=rand()%n;
        while(mp[{m1,n1}]!=0)
        {
            m1=rand()%m;
            n1=rand()%n;
            
            if(mp[{m1,n1}]==0) break;
        }
        mp[{m1,n1}]++;
        return {m1,n1};
    }
    
    void reset()
    {
        mp.clear();
    }
};
