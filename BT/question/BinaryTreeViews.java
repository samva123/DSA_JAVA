import java.util.*;

class Node {
    int data;
    Node left, right;
    
    Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

public class BinaryTreeViews {

    // Top View
    public static void printTopView(Node root) {
        if (root == null) return;

        TreeMap<Integer, Integer> hdToNodeMap = new TreeMap<>();
        Queue<AbstractMap.SimpleEntry<Node, Integer>> q = new LinkedList<>();

        q.offer(new AbstractMap.SimpleEntry<>(root, 0));

        while (!q.isEmpty()) {
            AbstractMap.SimpleEntry<Node, Integer> temp = q.poll();
            Node frontNode = temp.getKey();
            int hd = temp.getValue();

            // Store only first occurrence for each horizontal distance
            hdToNodeMap.putIfAbsent(hd, frontNode.data);

            if (frontNode.left != null) {
                q.offer(new AbstractMap.SimpleEntry<>(frontNode.left, hd - 1));
            }
            if (frontNode.right != null) {
                q.offer(new AbstractMap.SimpleEntry<>(frontNode.right, hd + 1));
            }
        }

        System.out.println("Printing Top View:");
        for (int value : hdToNodeMap.values()) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    // Bottom View
    public static void printBottomView(Node root) {
        if (root == null) return;

        TreeMap<Integer, Integer> hdToNodeMap = new TreeMap<>();
        Queue<AbstractMap.SimpleEntry<Node, Integer>> q = new LinkedList<>();

        q.offer(new AbstractMap.SimpleEntry<>(root, 0));

        while (!q.isEmpty()) {
            AbstractMap.SimpleEntry<Node, Integer> temp = q.poll();
            Node frontNode = temp.getKey();
            int hd = temp.getValue();

            // Always overwrite to store the last occurrence for each horizontal distance
            hdToNodeMap.put(hd, frontNode.data);

            if (frontNode.left != null) {
                q.offer(new AbstractMap.SimpleEntry<>(frontNode.left, hd - 1));
            }
            if (frontNode.right != null) {
                q.offer(new AbstractMap.SimpleEntry<>(frontNode.right, hd + 1));
            }
        }

        System.out.println("Printing Bottom View:");
        for (int value : hdToNodeMap.values()) {
            System.out.print(value + " ");
        }
        System.out.println();
    }

    // Main function for testing
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.left = new Node(6);
        root.right.right = new Node(7);
        root.left.left.right = new Node(8);
        
        printTopView(root);
        printBottomView(root);
    }
}

