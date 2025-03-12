// class Solution {
//     public List<Integer> postorderTraversal(TreeNode root) {
//         if (root == null) return new ArrayList<>(); // Base case

//         List<Integer> left = postorderTraversal(root.left);  // Traverse left (L)
//         List<Integer> right = postorderTraversal(root.right); // Traverse right (R)
//         left.addAll(right); // Merge left and right lists
//         left.add(root.val); // Process current node (N)

//         return left;
//     }
// }


//////////////////////////both are c++ replicas////////////////////


// class Solution {
//     private List<Integer> result = new ArrayList<>(); // Store traversal result

//     public List<Integer> postorderTraversal(TreeNode root) {
//         if (root == null) return result; // Base case

//         postorderTraversal(root.left);  // Traverse left (L)
//         postorderTraversal(root.right); // Traverse right (R)
//         result.add(root.val); // Process current node (N)

//         return result;
//     }
// }






