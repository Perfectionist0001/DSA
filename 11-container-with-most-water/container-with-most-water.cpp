class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int n = height.size();
        int lp = 0;
        int rp = n - 1;
        while(lp < rp){
            int width = rp - lp;
            int heigh = min(height[lp],height[rp]);
            int currwater = width * heigh;
            maxwater = max(maxwater,currwater);
            if(height[lp] < height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return maxwater;
    }
};