// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int water = 0;
//         for (int i = 0; i < n; i++) {
//             int leftmax = height[i];
//             for (int j = 0; j <= i; j++) {
//                 leftmax = max(leftmax, height[j]);
//             }
//             int rightmax = height[i];
//             for (int j = i; j < n; j++) {
//                 rightmax = max(rightmax, height[j]);
//             }
//             water = water + min(leftmax, rightmax) - height[i];
//         }
//         return water;
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int left = 0;
//         int right = height.size() - 1;
//         int leftMax = 0;
//         int rightMax = 0;
//         int water = 0;
//         while (left <= right) {
//             if (height[left] <= height[right]) {
//                 if (height[left] >= leftMax)
//                     leftMax = height[left];
//                 else
//                     water = water + leftMax - height[left];
//                 left++;
//             } else {
//                 if (height[right] >= rightMax)
//                     rightMax = height[right];
//                 else
//                     water = water + rightMax - height[right];
//                 right--;
//             }
//         }
//         return water;
//     }
// };

class Solution {
    public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int>Lmax(n,0);
        vector<int>Rmax(n,0);
        Lmax[0] = height[0];
        Rmax[n - 1] = height[n - 1];
        for(int i = 1; i < n; i++){
            Lmax[i] = max(Lmax[i - 1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            Rmax[i] = max(Rmax[i + 1],height[i]);
        }
        for(int i = 0; i < n; i++){
            ans = (ans + min(Lmax[i],Rmax[i]) - height[i]);
        }
        return ans;
    }
};