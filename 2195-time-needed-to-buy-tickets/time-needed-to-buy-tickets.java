class Solution {
    public int timeRequiredToBuy(int[] tickets, int k) {
        Queue<Integer> queue = new LinkedList<>();
        int time = 0;
        for(int i = 0; i < tickets.length; i++){
            queue.offer(i);
        }
        while(!queue.isEmpty()){
            int currentIndex = queue.remove();
            tickets[currentIndex]--;
            time++;
            if(currentIndex == k && tickets[currentIndex] == 0) return time;
            if(tickets[currentIndex]!= 0)queue.offer(currentIndex);
        }
        return time;
    }
}


