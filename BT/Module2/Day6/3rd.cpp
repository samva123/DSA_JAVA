#include <iostream>
#include <queue>
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
    // Encodes the tree into a single string
    string serialize(TreeNode* root) {
        if (!root) return "";

        ostringstream out;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur) {
                out << cur->val << ",";
                q.push(cur->left);
                q.push(cur->right);
            } else {
                out << "#,";
            }

            
        }
        return out.str();
    }

    // Decodes the encoded data to reconstruct the tree
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream in(data);
        string val;
        getline(in, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(in, val, ',') && val != "#") {
                node->left = new TreeNode(stoi(val));
                q.push(node->left);
            }
            if (getline(in, val, ',') && val != "#") {
                node->right = new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
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
