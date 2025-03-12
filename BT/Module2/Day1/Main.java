package Module2.Day1;

public class Main {
    
}






// class Solution {
//     public int maxPathSum(TreeNode root) {
//         int[] maxi = new int[]{Integer.MIN_VALUE}; 
//         findMaxPathSum(root, maxi);
//         return maxi[0];
//     }

//     private int findMaxPathSum(TreeNode node, int[] maxi) {
//         if (node == null) return 0;

//         int leftMax = Math.max(0, findMaxPathSum(node.left, maxi));
//         int rightMax = Math.max(0, findMaxPathSum(node.right, maxi));

//         maxi[0] = Math.max(maxi[0], leftMax + rightMax + node.val);

//         return node.val + Math.max(leftMax, rightMax);
//     }
// }
