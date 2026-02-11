import java.util.*;

class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int rotation = 0;
        Stack<Integer> stack = new Stack<>();
        
        for(int i = sandwiches.length - 1; i >= 0; i--){
            stack.push(sandwiches[i]);
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < students.length; i++){
            queue.offer(students[i]);
        }
        
        while(!queue.isEmpty() && rotation != queue.size()){
            int currentStudent = queue.peek();
            int currentSandwich = stack.peek();
            
            if(currentStudent == currentSandwich){
                rotation = 0;
                queue.remove();
                stack.pop();
            }
            else{
                queue.offer(queue.remove());
                rotation++;
            }
        }
        
        return queue.size();
    }
}
