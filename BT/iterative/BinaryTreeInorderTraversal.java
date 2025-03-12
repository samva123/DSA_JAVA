package iterative;

                            
import java.util.*;

// import iterative.Two_stack.Node;

// Node class for the binary tree
class Node {
    int data;
    Node left, right;

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class Solution {
    public List<Integer> inorderTraversal(Node root) {
        List<Integer> result = new ArrayList<>();
        Stack<Node> st = new Stack<>();
        Node curr = root;

        while (curr != null || !st.isEmpty()) {
            while (curr != null) {
                st.push(curr);
                curr = curr.left; // Move left as much as possible
            }

            curr = st.pop();
            result.add(curr.data); // Process current node (N)

            curr = curr.right; // Move to the right subtree
        }

        return result;
    }
}

// Main function
public class BinaryTreeInorderTraversal {
    public static void main(String[] args) {
        // Creating a sample binary tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        Solution solution = new Solution();
        // Getting inorder traversal
        List<Integer> result = solution.inorderTraversal(root);

        // Displaying the inorder traversal result
        System.out.print("Inorder Traversal: ");
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}

                            
                        