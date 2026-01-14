package iterative.One_stack;

import java.util.Scanner;

class Node {
    int data;
    Node left, right;

    public Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTree {
    static Scanner sc = new Scanner(System.in);

    public static Node createTree() {
        System.out.println("Enter the value for Node:");
        int data = sc.nextInt();

        if (data == -1) {
            return null;
        }

        // Step1: Create Node
        Node root = new Node(data);
        // Step2: Create left subtree
        root.left = createTree();
        // Step3: Create right subtree
        root.right = createTree();
        return root;
    }

    public static void main(String[] args) {
        Node root = createTree();
        sc.close();
    }
}

