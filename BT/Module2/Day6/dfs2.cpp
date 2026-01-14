#include <iostream>
#include <sstream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function for serialization (Preorder Traversal)
    void serializeHelper(TreeNode* root, string &s) {
        if (!root) {
            s += "# ";  // Represent NULL nodes
            return;
        }
        s += to_string(root->val) + " ";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    // Convert tree to string
    string serialize(TreeNode* root) {
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    // Helper function for deserialization
    TreeNode* deserializeHelper(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;  // NULL node

        TreeNode* node = new TreeNode(stoi(val));  // Create new node
        node->left = deserializeHelper(in);  // Recursively build left
        node->right = deserializeHelper(in);  // Recursively build right
        return node;
    }

    // Convert string back to tree
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
};

// Function to print inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;
    cout << "Original Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = solution.deserialize(serialized);
    cout << "Tree after deserialization: ";
    inorder(deserialized);
    cout << endl;

    return 0;
}
