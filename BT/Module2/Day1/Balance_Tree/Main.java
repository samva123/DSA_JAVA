package Module2.Day1.Balance_Tree;

public class Main {
    
}


// class TreeNode {
//     int val;
//     TreeNode left, right;
    
//     TreeNode(int x) {
//         val = x;
//         left = right = null;
//     }
// }

// class Solution {
//     public boolean isBalanced(TreeNode root) {
//         return dfsHeight(root) != -1;
//     }

//     private int dfsHeight(TreeNode root) {
//         if (root == null) return 0;

//         int leftHeight = dfsHeight(root.left);
//         if (leftHeight == -1) return -1;

//         int rightHeight = dfsHeight(root.right);
//         if (rightHeight == -1) return -1;

//         if (Math.abs(leftHeight - rightHeight) > 1) return -1;

//         return Math.max(leftHeight, rightHeight) + 1;
//     }
// }





// class Solution {
//     public boolean isBalanced(TreeNode root) {
//         boolean[] isBalanced = new boolean[]{true};
//         height(root, isBalanced);
//         return isBalanced[0];
//     }

//     private int height(TreeNode root, boolean[] isBalanced) {
//         if (root == null) return 0;

//         int lh = height(root.left, isBalanced);
//         int rh = height(root.right, isBalanced);

//         if (isBalanced[0] && Math.abs(lh - rh) > 1) {
//             isBalanced[0] = false;
//         }

//         return Math.max(lh, rh) + 1;
//     }
// }

