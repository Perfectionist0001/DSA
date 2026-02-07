class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        ListNode first = list1;
        ListNode second = list2;
        ListNode head;
        if (first.val <= second.val) {
            head = first;
            first = first.next;
        } else {
            head = second;
            second = second.next;
        }
        ListNode curr = head;
        while (first != null && second != null) {
            if (first.val <= second.val) {
                curr.next = first;
                first = first.next;
            } else {
                curr.next = second;
                second = second.next;
            }
            curr = curr.next;
        }
        if (first != null) curr.next = first;
        else curr.next = second;
        return head;
    }
}