package PalindromeLL;

// Node class represents a node in a linked list
class Node {
    int data;      // Data stored in the node
    Node next;     // Pointer to the next node in the list

    // Constructor with both data and next node as parameters
    Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    // Constructor with only data as a parameter, sets next to null
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class PalindromeLL {
    // Function to reverse a linked list using the recursive approach
    public static Node reverseLinkedList(Node head) {
        if (head == null || head.next == null) {
            return head; // Base case: empty list or single node
        }

        // Reverse the rest of the list recursively
        Node newHead = reverseLinkedList(head.next);

        // Reverse the current link
        head.next.next = head;
        head.next = null;

        return newHead; // Return the new head of the reversed list
    }

    // Function to check if a linked list is a palindrome
    public static boolean isPalindrome(Node head) {
        if (head == null || head.next == null) {
            return true; // A single node or empty list is a palindrome
        }

        // Find the middle of the linked list
        Node slow = head;
        Node fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Reverse the second half of the linked list
        Node newHead = reverseLinkedList(slow.next);

        // Compare the first and second halves
        Node first = head;
        Node second = newHead;
        boolean isPalindrome = true;
        while (second != null) {
            if (first.data != second.data) {
                isPalindrome = false;
                break;
            }
            first = first.next;
            second = second.next;
        }

        // Restore the original order of the linked list
        reverseLinkedList(newHead);

        return isPalindrome; // Return whether the list is a palindrome
    }

    // Function to print the linked list
    public static void printLinkedList(Node head) {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
        Node head = new Node(1);
        head.next = new Node(5);
        head.next.next = new Node(2);
        head.next.next.next = new Node(5);
        head.next.next.next.next = new Node(1);

        // Print the original linked list
        System.out.print("Original Linked List: ");
        printLinkedList(head);

        // Check if the linked list is a palindrome
        if (isPalindrome(head)) {
            System.out.println("The linked list is a palindrome.");
        } else {
            System.out.println("The linked list is not a palindrome.");
        }
    }
}
