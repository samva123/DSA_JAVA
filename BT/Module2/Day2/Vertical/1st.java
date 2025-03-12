package Module2.Day2.Vertical;



import java.util.*;



class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

// Custom Pair class for BFS
class Pair<U, V> {
    public final U key;
    public final V value;
    
    public Pair(U key, V value) {
        this.key = key;
        this.value = value;
    }

    public U getKey() { return key; }
    public V getValue() { return value; }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;

        Queue<Pair<TreeNode, Pair<Integer, Integer>>> q = new LinkedList<>();
        q.offer(new Pair<>(root, new Pair<>(0, 0))); // (node, (row, col))

        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();

        while (!q.isEmpty()) {
            Pair<TreeNode, Pair<Integer, Integer>> front = q.poll();
            TreeNode node = front.getKey();
            int row = front.getValue().getKey();
            int col = front.getValue().getValue();

            map.putIfAbsent(col, new TreeMap<>());
            map.get(col).putIfAbsent(row, new PriorityQueue<>());
            map.get(col).get(row).offer(node.val);

            if (node.left != null) q.offer(new Pair<>(node.left, new Pair<>(row + 1, col - 1)));
            if (node.right != null) q.offer(new Pair<>(node.right, new Pair<>(row + 1, col + 1)));
        }

        for (TreeMap<Integer, PriorityQueue<Integer>> colMap : map.values()) {
            List<Integer> vertical = new ArrayList<>();
            for (PriorityQueue<Integer> nodes : colMap.values()) {
                while (!nodes.isEmpty()) {
                    vertical.add(nodes.poll());
                }
            }
            ans.add(vertical);
        }
        return ans;
    }

    // Main method to test the BFS approach
    public static void main(String[] args) {
        Solution sol = new Solution();

        // Creating a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        // Testing BFS verticalTraversal
        System.out.println("Vertical Order (BFS): " + sol.verticalTraversal(root));
    }
}

























// package Vertical;

// import java.util.*;

// class TreeNode {
//     int val;
//     TreeNode left, right;
//     TreeNode(int x) { val = x; }
// }

// class Solution {
//     public List<List<Integer>> verticalTraversal(TreeNode root) {
//         List<List<Integer>> ans = new ArrayList<>();
//         if (root == null) return ans;

//         Queue<AbstractMap.SimpleEntry<TreeNode, AbstractMap.SimpleEntry<Integer, Integer>>> q = new LinkedList<>();
//         q.offer(new AbstractMap.SimpleEntry<>(root, new AbstractMap.SimpleEntry<>(0, 0))); // (node, (row, col))

//         TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();

//         while (!q.isEmpty()) {
//             AbstractMap.SimpleEntry<TreeNode, AbstractMap.SimpleEntry<Integer, Integer>> front = q.poll();
//             TreeNode node = front.getKey();
//             int row = front.getValue().getKey();
//             int col = front.getValue().getValue();

//             map.putIfAbsent(col, new TreeMap<>());
//             map.get(col).putIfAbsent(row, new PriorityQueue<>());
//             map.get(col).get(row).offer(node.val);

//             if (node.left != null) 
//                 q.offer(new AbstractMap.SimpleEntry<>(node.left, new AbstractMap.SimpleEntry<>(row + 1, col - 1)));
//             if (node.right != null) 
//                 q.offer(new AbstractMap.SimpleEntry<>(node.right, new AbstractMap.SimpleEntry<>(row + 1, col + 1)));
//         }

//         for (TreeMap<Integer, PriorityQueue<Integer>> colMap : map.values()) {
//             List<Integer> vertical = new ArrayList<>();
//             for (PriorityQueue<Integer> nodes : colMap.values()) {
//                 while (!nodes.isEmpty()) {
//                     vertical.add(nodes.poll());
//                 }
//             }
//             ans.add(vertical);
//         }
//         return ans;
//     }

//     public static void main(String[] args) {
//         Solution sol = new Solution();

//         // Creating a sample binary tree
//         TreeNode root = new TreeNode(1);
//         root.left = new TreeNode(2);
//         root.right = new TreeNode(3);
//         root.left.left = new TreeNode(4);
//         root.left.right = new TreeNode(5);
//         root.right.left = new TreeNode(6);
//         root.right.right = new TreeNode(7);

//         // Testing BFS verticalTraversal
//         System.out.println("Vertical Order (BFS): " + sol.verticalTraversal(root));
//     }
// }

