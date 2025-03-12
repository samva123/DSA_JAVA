// package Vertical;
// /**
//  * Definition for a binary tree node.
//  * public class TreeNode {
//  *     int val;
//  *     TreeNode left;
//  *     TreeNode right;
//  *     TreeNode() {}
//  *     TreeNode(int val) { this.val = val; }
//  *     TreeNode(int val, TreeNode left, TreeNode right) {
//  *         this.val = val;
//  *         this.left = left;
//  *         this.right = right;
//  *     }
//  * }
//  */
// import java.util.*;

// class Solution {
//     public List<List<Integer>> verticalTraversal(TreeNode root) {
//         List<List<Integer>> ans = new ArrayList<>();
//         if (root == null) return ans;

//         Queue<Pair<TreeNode, Pair<Integer, Integer>>> q = new LinkedList<>();
//         q.offer(new Pair<>(root, new Pair<>(0, 0)));

//         TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();

//         while (!q.isEmpty()) {
//             Pair<TreeNode, Pair<Integer, Integer>> front = q.poll();
//             TreeNode node = front.getKey();
//             int row = front.getValue().getKey();
//             int col = front.getValue().getValue();

//             map.putIfAbsent(col, new TreeMap<>());
//             map.get(col).putIfAbsent(row, new PriorityQueue<>());
//             map.get(col).get(row).offer(node.val);

//             if (node.left != null) q.offer(new Pair<>(node.left, new Pair<>(row + 1, col - 1)));
//             if (node.right != null) q.offer(new Pair<>(node.right, new Pair<>(row + 1, col + 1)));
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
// }


// ///above one is for leetcode bacuse it has a built in java class but if we have to 
// /// run it in vs code we have to write the other codes 
//watch it on leetcode 