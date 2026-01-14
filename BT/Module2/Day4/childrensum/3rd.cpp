#include <queue>




// class Solution {
// public:
//     int isSumProperty(Node* root) {
//         if (!root) return 1;

//         queue<Node*> q;
//         q.push(root);

//         while (!q.empty()) {
//             Node* node = q.front();
//             q.pop();

//             int childSum = 0;
//             if (node->left) {
//                 childSum += node->left->data;
//                 q.push(node->left);
//             }
//             if (node->right) {
//                 childSum += node->right->data;
//                 q.push(node->right);
//             }

//             if ((node->left || node->right) && node->data != childSum)
//                 return 0;
//         }

//         return 1;
//     }
// };










// class Solution {
//     public:
//         // Function to check whether all nodes of a tree satisfy
//         // the children sum property.
//         int isSumProperty(Node* root) {
//             // Base case: If the root is NULL or a leaf node, return true.
//             if (!root || (!root->left && !root->right)) {
//                 return 1;
//             }
    
//             // Calculate the sum of the left and right children.
//             int childSum = 0;
//             if (root->left) childSum += root->left->data;
//             if (root->right) childSum += root->right->data;
    
//             // Check the sum property and recurse on left and right subtrees.
//             if (root->data == childSum &&
//                 isSumProperty(root->left) &&
//                 isSumProperty(root->right)) {
//                 return 1;
//             }
    
//             // If any condition fails, return false.
//             return 0;
//         }
//     };



// Summary of Complexities
// Approach	Time Complexity	Space Complexity
// Iterative (BFS)	O(N)	O(N) (queue stores up to N/2 nodes)
// Recursive (DFS)	O(N)	O(N) (worst case), O(log N) (best case for balanced tree)
// Both methods have the same time complexity O(N), but the recursive approach may use less space (O(log N)) for a balanced tree. 🚀