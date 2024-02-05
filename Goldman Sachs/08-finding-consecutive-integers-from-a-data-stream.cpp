class DataStream {
    map<int, int> mp;
    int val, size;
public:
    DataStream(int value, int k) {
        val = value; 
        size = k;
        mp[value] = k;
    }
    
    bool consec(int num) {
        if(num==val)    mp[val]--;
        else            mp[val] = size;
        return mp[val]<=0;
    }
};