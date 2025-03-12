package Module2.Day1.Depth_of_Tree.Pair_java_approach;

public class Main {
    
}



// import java.util.*;

// class TreeNode {
//     int val;
//     TreeNode left, right;
    
//     TreeNode(int val) {
//         this.val = val;
//         this.left = this.right = null;
//     }
// }

// class Pair<K, V> {
//     private K key;
//     private V value;
    
//     Pair(K key, V value) {
//         this.key = key;
//         this.value = value;
//     }
    
//     public K getKey() { return key; }
//     public V getValue() { return value; }
// }

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

// public class Main {
//     public static void main(String[] args) {
//         TreeNode root = new TreeNode(1);
//         root.left = new TreeNode(2);
//         root.right = new TreeNode(3);
//         root.left.left = new TreeNode(4);
//         root.left.right = new TreeNode(5);

//         Solution sol = new Solution();
//         System.out.println("Max Depth: " + sol.maxDepth(root));  // Output: 3
//     }
// }



// import java.util.*;

// class Solution {
//     public int maxDepth(TreeNode root) {
//         if (root == null) return 0;
//         Stack<AbstractMap.SimpleEntry<TreeNode, Integer>> stack = new Stack<>();
//         stack.push(new AbstractMap.SimpleEntry<>(root, 1));
//         int maxDepth = 0;

//         while (!stack.isEmpty()) {
//             AbstractMap.SimpleEntry<TreeNode, Integer> pair = stack.pop();
//             TreeNode node = pair.getKey();
//             int depth = pair.getValue();
//             maxDepth = Math.max(maxDepth, depth);
//             if (node.left != null) stack.push(new AbstractMap.SimpleEntry<>(node.left, depth + 1));
//             if (node.right != null) stack.push(new AbstractMap.SimpleEntry<>(node.right, depth + 1));
//         }
//         return maxDepth;
//     }
// }









// import java.util.*;

// class TreeNode {
//     int val;
//     TreeNode left, right;

//     TreeNode(int val) {
//         this.val = val;
//         this.left = this.right = null;
//     }
// }

// class Solution {
//     public int maxDepth(TreeNode root) {
//         if (root == null) return 0;
//         Stack<Object[]> stack = new Stack<>();
//         stack.push(new Object[]{root, 1});
//         int maxDepth = 0;

//         while (!stack.isEmpty()) {
//             Object[] arr = stack.pop();
//             TreeNode node = (TreeNode) arr[0];
//             int depth = (int) arr[1];
//             maxDepth = Math.max(maxDepth, depth);
            
//             if (node.left != null) stack.push(new Object[]{node.left, depth + 1});
//             if (node.right != null) stack.push(new Object[]{node.right, depth + 1});
//         }
//         return maxDepth;
//     }
// }

// public class Main {
//     public static void main(String[] args) {
//         TreeNode root = new TreeNode(1);
//         root.left = new TreeNode(2);
//         root.right = new TreeNode(3);
//         root.left.left = new TreeNode(4);
//         root.left.right = new TreeNode(5);

//         Solution sol = new Solution();
//         System.out.println("Max Depth: " + sol.maxDepth(root));  // Output: 3
//     }
// }

