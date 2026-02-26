class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        return helper(n, cost, dp);
    }
    public int helper(int i, int[] cost, int[] dp) {
        if (i == 0 || i == 1) return 0;
        if (dp[i] != -1) return dp[i];
        int oneStep = cost[i - 1] + helper(i - 1, cost, dp);
        int twoStep = cost[i - 2] + helper(i - 2, cost, dp);
        dp[i] = Math.min(oneStep, twoStep);
        return dp[i];
    }
}



