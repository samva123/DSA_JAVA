package Module2.Day4.width;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }
}

class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        Queue<AbstractMap.SimpleEntry<TreeNode, Long>> q = new LinkedList<>();
        q.add(new AbstractMap.SimpleEntry<>(root, 0L));
        int maxWidth = 0;

        while (!q.isEmpty()) {
            int levelSize = q.size();
            long levelStart = q.peek().getValue();
            long levelEnd = levelStart;

            for (int i = 0; i < levelSize; i++) {
                AbstractMap.SimpleEntry<TreeNode, Long> front = q.poll();
                TreeNode node = front.getKey();
                long position = front.getValue();

                if (i == levelSize - 1) {
                    levelEnd = position;
                }

                if (node.left != null) {
                    q.add(new AbstractMap.SimpleEntry<>(node.left, position * 2));
                }
                if (node.right != null) {
                    q.add(new AbstractMap.SimpleEntry<>(node.right, position * 2 + 1));
                }
            }
            maxWidth = Math.max(maxWidth, (int) (levelEnd - levelStart + 1));
        }
        return maxWidth;
    }
}

