class Solution {
    public boolean find132pattern(int[] nums) {

        int n = nums.length;
        if (n < 3) return false;

        int[] minTillNow = new int[n];
        minTillNow[0] = nums[0];

        for (int i = 1; i < n; i++) {
            minTillNow[i] = Math.min(minTillNow[i - 1], nums[i]);
        }

        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {

            if (nums[i] > minTillNow[i]) {

                while (!stack.isEmpty() && stack.peek() <= minTillNow[i]) {
                    stack.pop();
                }

                if (!stack.isEmpty() && stack.peek() < nums[i]) {
                    return true;
                }

                stack.push(nums[i]);
            }
        }

        return false;
    }
}
