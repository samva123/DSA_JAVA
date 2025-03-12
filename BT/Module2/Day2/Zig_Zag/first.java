package Module2.Day2.Zig_Zag;

public class first {
    
}


// import java.util.*;

// class TreeNode {
//     int val;
//     TreeNode left, right;
//     TreeNode(int x) { val = x; }
// }

// class Solution {
//     public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
//         List<List<Integer>> ans = new ArrayList<>();
//         if (root == null) return ans;

//         boolean leftToRight = true;
//         Queue<TreeNode> q = new LinkedList<>();
//         q.add(root);

//         while (!q.isEmpty()) {
//             int size = q.size();
//             List<Integer> oneLevel = new ArrayList<>(size);

//             for (int i = 0; i < size; ++i) {
//                 TreeNode node = q.poll();
//                 int index = leftToRight ? i : size - i - 1;
//                 if (oneLevel.size() <= index) oneLevel.add(node.val);
//                 else oneLevel.add(index, node.val);

//                 if (node.left != null) q.add(node.left);
//                 if (node.right != null) q.add(node.right);
//             }

//             leftToRight = !leftToRight;
//             ans.add(oneLevel);
//         }
//         return ans;
//     }
// }

// import java.util.*;

// class Solution {
//     public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
//         List<List<Integer>> ans = new ArrayList<>();
//         if (root == null) return ans;

//         Queue<TreeNode> q = new LinkedList<>();
//         q.add(root);
//         boolean leftToRight = true;

//         while (!q.isEmpty()) {
//             int size = q.size();
//             Deque<Integer> level = new LinkedList<>();

//             for (int i = 0; i < size; ++i) {
//                 TreeNode node = q.poll();
//                 if (leftToRight) 
//                     level.addLast(node.val);
//                 else 
//                     level.addFirst(node.val);

//                 if (node.left != null) q.add(node.left);
//                 if (node.right != null) q.add(node.right);
//             }

//             ans.add(new ArrayList<>(level));
//             leftToRight = !leftToRight;
//         }
//         return ans;
//     }
// }






// import java.util.*;

// class Solution {
//     private void dfs(TreeNode node, int level, List<List<Integer>> result) {
//         if (node == null) return;

//         if (result.size() == level) 
//             result.add(new ArrayList<>());

//         if (level % 2 == 0)
//             result.get(level).add(node.val);
//         else
//             result.get(level).add(0, node.val); // Insert at the front

//         dfs(node.left, level + 1, result);
//         dfs(node.right, level + 1, result);
//     }

//     public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
//         List<List<Integer>> result = new ArrayList<>();
//         dfs(root, 0, result);
//         return result;
//     }
// }
