// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         // unordered_map<int,int> freq;
//         // for(int x : nums)
//         // {
//         //     freq[x]++;
//         // }
//         // sort(nums.begin(), nums.end(), [&](int a, int b)
//         // {
//         //     if(freq[a] == freq[b])
//         //     {
//         //         return a > b;
//         //     }
//         //     return freq[a] < freq[b];
//         // });
//         // return nums;
//         int n = nums.size();
//         int freq1 = 0;
//         int freq2 = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 for(int k = 0; k < n; k++){
//                     if(nums[k] == nums[i]){
//                         freq1++;
//                     }
//                     if(nums[k] == nums[j]){
//                         freq2++;
//                     }
//                     if (freq1 > freq2 || (freq1 == freq2 && nums[i] < nums[j])){
//                         swap(nums[i] , nums[j]);
//                     }
//                 }
//             }
//         }
//         return nums;
//     }
// };
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int freq1 = 0;
                int freq2 = 0;
                for(int k = 0; k < n; k++)
                {
                    if(nums[k] == nums[i])
                    {
                        freq1++;
                    }

                    if(nums[k] == nums[j])
                    {
                        freq2++;
                    }
                }
                if(freq1 > freq2 || (freq1 == freq2 && nums[i] < nums[j]))
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
        return nums;
    }
};