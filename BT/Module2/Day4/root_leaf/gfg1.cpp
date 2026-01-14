
//  https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

// bool hasPathSum(Node* root, int target) {
//     if (root == NULL)
//         return false;

//     // leaf node
//     if (root->left == NULL && root->right == NULL) {
//         return target == root->data;
//     }

//     int remaining = target - root->data;

//     return hasPathSum(root->left, remaining) ||
//            hasPathSum(root->right, remaining);
// }



// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int target) {
//         if (!root) return false;

//         queue<pair<TreeNode*, int>> q;
//         q.push({root, target});

//         while (!q.empty()) {
//             auto front = q.front();
//             q.pop();

//             TreeNode* node = front.first;
//             int remaining = front.second - node->val;

//             // check only at leaf
//             if (!node->left && !node->right) {
//                 if (remaining == 0)
//                     return true;
//             }

//             if (node->left)
//                 q.push({node->left, remaining});
//             if (node->right)
//                 q.push({node->right, remaining});
//         }

//         return false;
//     }
// };
