class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0;
        int high = k - 1;
        int result = 0;
        int zero = 0;
        for(high = 0; high < n; high++){
             if(nums[high] == 0)
                zero++;
            while(zero > k) {
                if(nums[low] == 0)
                    zero--;
                low++;
            }
            int length = high - low + 1;
            result = max(result,length);
        }
        return result;
    }
};