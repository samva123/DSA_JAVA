package SortList;

// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode() {
        this.val = 0;
        this.next = null;
    }
    ListNode(int val) {
        this.val = val;
        this.next = null;
    }
    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode merge(ListNode left, ListNode right) {
        if (left == null) return right;
        if (right == null) return left;

        ListNode ans = new ListNode(-1); // Dummy node
        ListNode mptr = ans;

        while (left != null && right != null) {
            if (left.val <= right.val) {
                mptr.next = left;
                mptr = left;
                left = left.next;
            } else {
                mptr.next = right;
                mptr = right;
                right = right.next;
            }
        }

        while (left != null) {
            mptr.next = left;
            mptr = left;
            left = left.next;
        }

        while (right != null) {
            mptr.next = right;
            mptr = right;
            right = right.next;
        }

        return ans.next; // Return merged list starting from the next of dummy node
    }

    public ListNode findMid(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null; // To keep track of the node before mid

        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Disconnect the left half from the right half
        if (prev != null) {
            prev.next = null; // This will break the link between left and right halves
        }

        return slow;
    }

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode mid = findMid(head); // mid is the start of the right half
        ListNode left = head;
        ListNode right = mid;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
}

