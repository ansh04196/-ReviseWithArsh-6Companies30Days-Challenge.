class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
    
        long arraySum = 0, originalValue = 0;
        
        for(int i = 0; i < nums.size(); i++){
            arraySum += nums[i];
            originalValue += i * nums[i];
        }
        
        long maximumValue = originalValue;
        int n = nums.size();
        
        for(int i = n - 1; i >= 0; i--)
        {
            originalValue += arraySum - (nums[i] * n);
            maximumValue = max(originalValue, maximumValue);
        }
        return maximumValue;
    }   
};

     