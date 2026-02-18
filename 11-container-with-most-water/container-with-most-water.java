class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int max_area = 0;
        while(i < j){
            int current_base = j - i;
            int min_side = Math.min(height[i],height[j]);
            int current_area = current_base * min_side;

            if(current_area > max_area){
                max_area = current_area;
            }
            if(height[i] >= height[j]) j--;
            else i++;
        }
        return max_area;
    }
}
