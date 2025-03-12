package Module2.Day1.Diameter_of_Tree;

public class Main {
    
}


// class TreeNode {
//     int val;
//     TreeNode left, right;
//     TreeNode(int val) {
//         this.val = val;
//         this.left = this.right = null;
//     }
// }

// class Solution {
//     public int height(TreeNode root) {
//         if (root == null) {
//             return 0;
//         }
//         int leftHeight = height(root.left);
//         int rightHeight = height(root.right);
//         return 1 + Math.max(leftHeight, rightHeight);
//     }

//     public int diameterOfBinaryTree(TreeNode root) {
//         if (root == null) {
//             return 0;
//         }
//         int option1 = diameterOfBinaryTree(root.left);
//         int option2 = diameterOfBinaryTree(root.right);
//         int option3 = height(root.left) + height(root.right);
//         return Math.max(option1, Math.max(option2, option3));
//     }
// }



// class TreeNode {
//     int val;
//     TreeNode left, right;
//     TreeNode(int val) {
//         this.val = val;
//         this.left = this.right = null;
//     }
// }

// class Solution {
//     public int diameterOfBinaryTree(TreeNode root) {
//         int[] diameter = new int[1]; // Using an array to store diameter reference
//         height(root, diameter);
//         return diameter[0];
//     }

//     private int height(TreeNode node, int[] diameter) {
//         if (node == null) {
//             return 0;
//         }

//         int leftHeight = height(node.left, diameter);
//         int rightHeight = height(node.right, diameter);

//         diameter[0] = Math.max(diameter[0], leftHeight + rightHeight);

//         return 1 + Math.max(leftHeight, rightHeight);
//     }
// }





// Comparison of Both Approaches
// Approach	Time Complexity	Space Complexity	Explanation
// Brute Force	O(N²)	O(N)	Recursively calculates height multiple times
// Optimized	O(N)	O(N) (worst), O(log N) (balanced)	Uses single traversal with height and diameter update
// The optimized approach is clearly better because it eliminates redundant height calculations.

// Let me know if you need further explanations! 🚀