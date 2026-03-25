class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool ok=next_permutation(nums.begin(),nums.end());
        if(!ok)
        {
            sort(nums.begin(),nums.end());
        }
    }
};