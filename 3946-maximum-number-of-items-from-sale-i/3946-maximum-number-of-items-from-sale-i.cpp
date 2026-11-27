class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int p = items[i][1], cnt = 1;
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    cnt++;
            }
            vector<int> ndp = dp;
            for (int j = p; j <= budget; j++)
                ndp[j] = max(ndp[j], dp[j - p] + cnt);
            for (int j = p; j <= budget; j++)
                ndp[j] = max(ndp[j], ndp[j - p] + 1);
            dp = ndp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};