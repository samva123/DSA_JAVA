import java.util.*;

 // Definition for singly-linked list.
  public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
 
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode h1 = head; // Pointer to odd nodes
        ListNode h2 = head.next; // Pointer to even nodes
        ListNode evenHead = h2; // Store the start of the even list

        while (h2 != null && h2.next != null) {
            h1.next = h2.next; // Link the next odd node
            h1 = h1.next; // Move the odd pointer
            h2.next = h1.next; // Link the next even node
            h2 = h2.next; // Move the even pointer
        }

        h1.next = evenHead; // Append even list at the end of the odd list
        return head;

        
    }
}