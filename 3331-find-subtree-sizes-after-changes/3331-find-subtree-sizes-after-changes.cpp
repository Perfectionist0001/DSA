class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> newParent = parent;
        function<void(int, vector<int>)> dfs = [&](int node, vector<int> last) {
            int c = s[node] - 'a';
            if (last[c] != -1) {
                newParent[node] = last[c];
            }
            last[c] = node;
            for (int child : adj[node]) {
                dfs(child, last);
            }
        };
        vector<int> last(26, -1);
        dfs(0, last);
        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }
        vector<int> ans(n, 1);
        function<int(int)> solve = [&](int node) {
            for (int child : tree[node]) {
                ans[node] += solve(child);
            }
            return ans[node];
        };
        solve(0);
        return ans;
    }
};