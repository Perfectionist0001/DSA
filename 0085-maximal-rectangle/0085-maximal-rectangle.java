class Solution {

    public int largestRectangleArea(int[] heights) {
        int n = heights.length;

        int[] nextSmaller = new int[n];
        Stack<Integer> stack1 = new Stack<>();

        for (int i = n - 1; i >= 0; i--) { 
            int current = heights[i];
            while (!stack1.isEmpty() && current <= heights[stack1.peek()]) {
                stack1.pop();
            }
            if (stack1.isEmpty()) nextSmaller[i] = n;
            else nextSmaller[i] = stack1.peek();
            stack1.push(i);
        }

        int[] prevSmaller = new int[n];
        Stack<Integer> stack2 = new Stack<>();

        for (int i = 0; i < n; i++) {
            int current = heights[i];
            while (!stack2.isEmpty() && current <= heights[stack2.peek()]) {
                stack2.pop();
            }
            if (stack2.isEmpty()) prevSmaller[i] = -1;
            else prevSmaller[i] = stack2.peek();
            stack2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int currentArea = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i];
            maxArea = Math.max(maxArea, currentArea);
        }
        return maxArea;
    }

    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int[][] array = new int[m][n];
        for (int j = 0; j < n; j++) {
            array[0][j] = matrix[0][j] - '0';
        }
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (matrix[i][j] != '0') {
                    array[i][j] = array[i - 1][j] + 1;
                } else {
                    array[i][j] = 0;
                }
            }
        }

        int maxRectangle = 0;
        for (int i = 0; i < m; i++) {
            int currentArea = largestRectangleArea(array[i]);
            maxRectangle = Math.max(maxRectangle, currentArea);
        }

        return maxRectangle;
    }
}

