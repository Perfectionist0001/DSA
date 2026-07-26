class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // int n = nums.size();
        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         for(int k = j + 1; k < n; k++){
        //             ans = max(ans, nums[i] * nums[j] * nums[k]);
        //         }
        //     }
        // }
        // return ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};