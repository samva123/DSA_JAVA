package Module2.Day2.Vertical;

import java.util.*;



class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class Solution {
    TreeMap<Integer, TreeMap<Integer, List<Integer>>> nodes = new TreeMap<>();

    private void dfs(TreeNode root, int row, int col) {
        if (root == null) return;

        nodes.putIfAbsent(col, new TreeMap<>());
        nodes.get(col).putIfAbsent(row, new ArrayList<>());
        nodes.get(col).get(row).add(root.val);

        dfs(root.left, row + 1, col - 1);
        dfs(root.right, row + 1, col + 1);
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) return ans;

        dfs(root, 0, 0);

        for (TreeMap<Integer, List<Integer>> colMap : nodes.values()) {
            List<Integer> vertical = new ArrayList<>();
            for (List<Integer> values : colMap.values()) {
                Collections.sort(values);
                vertical.addAll(values);
            }
            ans.add(vertical);
        }
        return ans;
    }

    // Main method to test the DFS approach
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

        // Testing DFS verticalTraversal
        System.out.println("Vertical Order (DFS): " + sol.verticalTraversal(root));
    }
}


