class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int maximum = nums[0];
        int minimum = nums[0];
        for(int i = 0; i < n; i++){
            if(nums[i] < minimum){
                minimum = nums[i];
            }
            if(nums[i] > maximum){
                maximum = nums[i];
            }
        }
        for(int i = minimum; i <= maximum; i++){
            bool found = false;
            for(int j = 0; j < n; j++){
                if(nums[j] == i){
                    found = true;
                    break;
                }
            }
            if(!found){
                ans.push_back(i);
            }
        }
        return ans;
    }
};