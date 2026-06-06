class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int n = nums.size();
        // for(int i = 0; i < n; i++){
        //     for(int j = i + 1; j < n; j++){
        //         if(nums[i] == nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};