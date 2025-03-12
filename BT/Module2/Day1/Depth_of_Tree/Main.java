package Module2.Day1.Depth_of_Tree;

public class Main {
    
}


// class Solution {
//     public int maxDepth(TreeNode root) {
//         if (root == null) return 0;
//         int leftDepth = maxDepth(root.left);
//         int rightDepth = maxDepth(root.right);
//         return Math.max(leftDepth, rightDepth) + 1;
//     }
// }








// import java.util.*;

// class Solution {
//     public int maxDepth(TreeNode root) {
//         if (root == null) return 0;
//         Queue<TreeNode> queue = new LinkedList<>();
//         queue.add(root);
//         int depth = 0;
//         while (!queue.isEmpty()) {
//             int size = queue.size();
//             for (int i = 0; i < size; i++) {
//                 TreeNode node = queue.poll();
//                 if (node.left != null) queue.add(node.left);
//                 if (node.right != null) queue.add(node.right);
//             }
//             depth++;
//         }
//         return depth;
//     }
// }

















// import java.util.*;

// class Solution {
//     public int maxDepth(TreeNode root) {
//         if (root == null) return 0;
//         Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
//         stack.push(new Pair<>(root, 1));
//         int maxDepth = 0;
//         while (!stack.isEmpty()) {
//             Pair<TreeNode, Integer> pair = stack.pop();
//             TreeNode node = pair.getKey();
//             int depth = pair.getValue();
//             maxDepth = Math.max(maxDepth, depth);
//             if (node.left != null) stack.push(new Pair<>(node.left, depth + 1));
//             if (node.right != null) stack.push(new Pair<>(node.right, depth + 1));
//         }
//         return maxDepth;
//     }
// }

