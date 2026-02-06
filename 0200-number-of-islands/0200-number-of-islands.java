class Solution {
    public int numIslands(char[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] visited = new int[m][n];
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    count++;
                    dfs(i, j, m, n, grid, visited);
                }
            }
        }
        return count;
    }
    public void dfs(int row, int col, int m, int n, char[][] grid, int[][] visited) {
        visited[row][col] = 1;

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if (newRow >= 0 && newRow < m &&
                newCol >= 0 && newCol < n &&
                grid[newRow][newCol] == '1' &&
                visited[newRow][newCol] == 0) {

                dfs(newRow, newCol, m, n, grid, visited);
            }
        }
    }
}
