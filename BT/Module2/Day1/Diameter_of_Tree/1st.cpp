// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
//     public:
//     int height(TreeNode* root) {
//         //base case
//         if(root == NULL ) {
//             return 0;
//         }
//         int leftHeight = height(root->left);
//         int rightHeight = height(root->right);
//         int height = max(leftHeight, rightHeight) + 1;
//         return height;
//     }
//       int diameterOfBinaryTree(TreeNode* root) {
//         //base case
//         if(root == NULL) {
//             return 0;
//         }   
//         int option1 = diameterOfBinaryTree(root->left);
//         int option2 = diameterOfBinaryTree(root->right);
//         int option3 = height(root->left) + height(root->right);
//         int diameter = max(option1, max(option2, option3));
//         return diameter;
//     }
//     };



// #include <iostream>
// #include <algorithm>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     int diameterOfBinaryTree(Node* root) {
//         int diameter = 0;
//         height(root, diameter);
//         return diameter;
//     }

// private:
//     int height(Node* node, int& diameter) {
//         if (!node) return 0;

//         int lh = height(node->left, diameter);
//         int rh = height(node->right, diameter);

//         diameter = max(diameter, lh + rh);

//         return 1 + max(lh, rh);
//     }
// };

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->left->right->right = new Node(6);
//     root->left->right->right->right = new Node(7);

//     Solution solution;
//     int diameter = solution.diameterOfBinaryTree(root);
//     cout << "The diameter of the binary tree is: " << diameter << endl;

//     return 0;
// }
