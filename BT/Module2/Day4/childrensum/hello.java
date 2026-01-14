package Module2.Day4.childrensum;

public class hello {
    
}


// import java.util.*;

// class Node {`
//     int data;
//     Node left, right;

//     Node(int item) {
//         data = item;
//         left = right = null;
//     }
// }

// class Solution {
//     public int isSumProperty(Node root) {
//         if (root == null) return 1;

//         Queue<Node> queue = new LinkedList<>();
//         queue.add(root);

//         while (!queue.isEmpty()) {
//             Node node = queue.poll();

//             int childSum = 0;
//             if (node.left != null) {
//                 childSum += node.left.data;
//                 queue.add(node.left);
//             }
//             if (node.right != null) {
//                 childSum += node.right.data;
//                 queue.add(node.right);
//             }

//             if ((node.left != null || node.right != null) && node.data != childSum)
//                 return 0;
//         }
//         return 1;
//     }
// }










// class Solution {
//     public int isSumProperty(Node root) {
//         // Base case: If the root is null or a leaf node, return true.
//         if (root == null || (root.left == null && root.right == null)) {
//             return 1;
//         }

//         // Calculate the sum of the left and right children.
//         int childSum = 0;
//         if (root.left != null) childSum += root.left.data;
//         if (root.right != null) childSum += root.right.data;

//         // Check the sum property and recurse on left and right subtrees.
//         if (root.data == childSum &&
//             isSumProperty(root.left) == 1 &&
//             isSumProperty(root.right) == 1) {
//             return 1;
//         }

//         // If any condition fails, return false.
//         return 0;
//     }
// }

