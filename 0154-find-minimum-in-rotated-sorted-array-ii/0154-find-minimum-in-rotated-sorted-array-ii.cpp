class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minimum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] < minimum){
                minimum = nums[i];
            }
        }
        return minimum;
    }
};

