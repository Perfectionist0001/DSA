class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < asteroids.length; i++) {
            int current = asteroids[i];

            if (current > 0) {
                stack.push(current);
            } else {
                boolean exploded = false;

                while (!stack.isEmpty() && stack.peek() > 0) {
                    int lastInStack = stack.peek();

                    if (Math.abs(current) > lastInStack) {
                        stack.pop();
                        continue;
                    } else if (Math.abs(current) == lastInStack) {
                        stack.pop();
                        exploded = true;
                        break;
                    } else {
                        exploded = true;
                        break;
                    }
                }
                if (!exploded) {
                    stack.push(current);
                }
            }
        }
        int[] result = new int[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }
        return result;
    }
}
