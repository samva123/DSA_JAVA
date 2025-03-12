                            
import java.util.ArrayList;
import java.util.List;

// Node class for the binary tree
class Node {
    int data;
    Node left;
    Node right;
    
    // Constructor to initialize
    // the node with a value
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

public class BinaryTreeInorderTraversal {

    // Function to perform inorder traversal
    // of the tree and store values in 'arr'
    public static void inorder(Node root, List<Integer> arr) {
        // If the current node is null
        // (base case for recursion), return
        if (root == null) {
            return;
        }
        // Recursively traverse the left subtree
        inorder(root.left, arr);
        // Push the current node's
        // value into the list
        arr.add(root.data);
        // Recursively traverse 
        // the right subtree
        inorder(root.right, arr);
    }

    // Function to initiate inorder traversal
    // and return the resulting list
    public static List<Integer> inOrder(Node root) {
        // Create an empty list to
        // store inorder traversal values
        List<Integer> arr = new ArrayList<>();
        // Call the inorder traversal function
        inorder(root, arr);
        // Return the resulting list
        // containing inorder traversal values
        return arr;
    }

    // Main function
    public static void main(String[] args) {
        // Creating a sample binary tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Getting inorder traversal
        List<Integer> result = inOrder(root);

        // Displaying the inorder traversal result
        System.out.print("Inorder Traversal: ");
        // Output each value in the
        // inorder traversal result
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}














// solution of my static confusion 
//(i am looking forward to make function static but that would not be possible bacuse main is static and we can only call static 
//if function is static so to call it without using static keyword we made a instance )


// import java.util.ArrayList;
// import java.util.List;

// // Node class for the binary tree
// class Node {
//     int data;
//     Node left;
//     Node right;
    
//     // Constructor to initialize the node with a value
//     Node(int val) {
//         data = val;
//         left = null;
//         right = null;
//     }
// }

// public class BinaryTreeInorderTraversal {

//     // Function to perform inorder traversal and store values in 'arr'
//     public void inorder(Node root, List<Integer> arr) {
//         if (root == null) {
//             return;
//         }
//         inorder(root.left, arr);  // Traverse left
//         arr.add(root.data);       // Process current node
//         inorder(root.right, arr); // Traverse right
//     }

//     // Function to initiate inorder traversal and return the resulting list
//     public List<Integer> inOrder(Node root) {
//         List<Integer> arr = new ArrayList<>();
//         inorder(root, arr);
//         return arr;
//     }

//     // Main function
//     public static void main(String[] args) {
//         // Creating an instance of BinaryTreeInorderTraversal
//         BinaryTreeInorderTraversal tree = new BinaryTreeInorderTraversal();

//         // Creating a sample binary tree
//         Node root = new Node(1);
//         root.left = new Node(2);
//         root.right = new Node(3);
//         root.left.left = new Node(4);
//         root.left.right = new Node(5);

//         // Getting inorder traversal
//         List<Integer> result = tree.inOrder(root); // Calling instance method

//         // Displaying the inorder traversal result
//         System.out.print("Inorder Traversal: ");
//         for (int val : result) {
//             System.out.print(val + " ");
//         }
//         System.out.println();
//     }
// }

                            
                        