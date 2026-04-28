class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        int n = nums1.size();
        int x = nums2.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < x; j++){
                if(nums1[i] == nums2[j]){
                    result.push_back (nums1[i]);
                    nums2[j] = -1;
                    break;
                }
            }
        }
        return result;
    }
};