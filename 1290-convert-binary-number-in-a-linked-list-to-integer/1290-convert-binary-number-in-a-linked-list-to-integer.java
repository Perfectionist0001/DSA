class Solution {
    public int getDecimalValue(ListNode head) {
        ListNode temp = head;
        int size = getSize(head);
        int sum = 0;
        for (int i = size - 1; i >= 0; i--) {
            int powerOfTwo = (int) Math.pow(2, i);
            sum += powerOfTwo * temp.val;
            temp = temp.next;
        }
        return sum;
    }
    public int getSize(ListNode head) {
        ListNode temp = head;
        int size = 0;
        while (temp != null) {
            size++;
            temp = temp.next;
        }
        return size;
    }
}
