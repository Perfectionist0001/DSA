class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int length = 0;
        int result = INT_MAX;
        while(right < n){
            sum = sum + nums[right];
            while(sum >= target){
                length = right - left + 1;
                result = min(result,length);
                sum = sum - nums[left];
                left++;
            }
            right++;
        }
        if(result == INT_MAX){
            return 0;
        }
        else{
            return result;
        }
    }
};