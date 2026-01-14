#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL )
            return NULL;
            if(root->val == p->val) {
                 return p;
            }
            if(root->val == q->val) {
                return q;
            }
            
            TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
            TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
    
            if(leftAns == NULL && rightAns == NULL)
                return NULL;
            else if(leftAns != NULL && rightAns == NULL)
                return leftAns;
            else if(leftAns == NULL && rightAns != NULL)
                return rightAns;
            else 
            return root;
    
    
    
            
        }
    };











// /**
//  * Definition for a binary tree node.
//  * public class TreeNode {
//  *     int val;
//  *     TreeNode left;
//  *     TreeNode right;
//  *     TreeNode(int x) { val = x; }
//  * }
//  */
// class Solution {
//     public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
//         HashMap<TreeNode,TreeNode> map = new HashMap<>();
//         Queue<TreeNode> qu = new LinkedList<>();
//         qu.add(root);
//         map.put(root,null);
//         while(!qu.isEmpty()){
//             int size = qu.size();
//             for(int i=0;i<size;i++){
//                 TreeNode curr = qu.poll();
//                 if(curr.left!=null){
//                     qu.add(curr.left);
//                     map.put(curr.left,curr);
//                 }
//                 if(curr.right!=null){
//                     qu.add(curr.right);
//                     map.put(curr.right,curr);
//                 }
//             }
//         }
//         int x = p.val;
//         int y = q.val;
//         HashSet<TreeNode> set = new HashSet<>();
//         while(p!=null){
//             set.add(p);
//             p=map.getOrDefault(p,null);
//         }
//         while(!set.contains(q)){
//             q=map.getOrDefault(q,null);
//         }
//         return q;
        
//     }
// }