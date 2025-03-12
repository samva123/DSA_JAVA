// class Solution {
//     public:
//         bool isBalanced(Node* root) {
//             return dfsHeight(root) != -1;
//         }
    
//         int dfsHeight(Node* root) {
//             if (root == NULL) return 0;
    
//             int leftHeight = dfsHeight(root->left);
//             if (leftHeight == -1) return -1;
    
//             int rightHeight = dfsHeight(root->right);
//             if (rightHeight == -1) return -1;
    
//             if (abs(leftHeight - rightHeight) > 1) return -1;
    
//             return max(leftHeight, rightHeight) + 1;
//         }
//     };





//     class Solution {
//         public:
//             int height(TreeNode* root, bool &isbalance) {
//                 if (!root) return 0;
        
//                 int lh = height(root->left, isbalance);
//                 int rh = height(root->right, isbalance);
        
//                 if (isbalance && abs(lh - rh) > 1) {
//                     isbalance = false;
//                 }
        
//                 return max(lh, rh) + 1;
//             }
        
//             bool isBalanced(TreeNode* root) {
//                 bool isbalance = true;
//                 height(root, isbalance);
//                 return isbalance;
//             }
//         };
        
    



        // Which Approach is Better?
        // Approach	Time Complexity	Space Complexity	Key Advantage
        // Returning -1 for unbalanced trees	O(N)	O(H) (O(log N) in balanced, O(N) in skewed)	Short-circuits early if a subtree is unbalanced
        // Using a boolean flag (isbalance)	O(N)	O(H) (O(log N) in balanced, O(N) in skewed)	More readable, but doesn't short-circuit
        // The first approach is better because:
        // It short-circuits early if a subtree is unbalanced.
        // Avoids unnecessary recursive calls in such cases.
        // So, I recommend the first approach as it can save some computations when the tree is unbalanced. 🚀