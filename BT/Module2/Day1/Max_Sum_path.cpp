


#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPathSum(root, maxi);
        return maxi;
    }

private:
    int findMaxPathSum(TreeNode* node, int &maxi) {
        if (!node) return 0;

        int leftMax = max(0, findMaxPathSum(node->left, maxi));
        int rightMax = max(0, findMaxPathSum(node->right, maxi));

        maxi = max(maxi, leftMax + rightMax + node->val);

        return node->val + max(leftMax, rightMax);
    }
};












// Time and Space Complexity of Brute Force
// Time Complexity: O(N²)
// For each node, we calculate the sum of all paths passing through it.
// In a balanced tree, height is O(log N), and in a skewed tree, height is O(N).
// In the worst case, for each node, we traverse O(N) nodes, leading to O(N²) time complexity.
// Space Complexity: O(N)
// In the worst case (skewed tree), the recursion stack takes O(N) space.
// For a balanced tree, the recursion depth is O(log N).









// Time and Space Complexity Analysis
// This solution finds the maximum path sum in a binary tree using post-order DFS traversal.

// Time Complexity: O(N)
// Each node is visited once, and all operations at each node (calculating left & right path sums and updating maxi) take O(1) time.
// Thus, the overall time complexity is O(N), where N is the number of nodes in the tree.
// Space Complexity: O(N)
// Recursive stack space: In the worst case (a skewed tree), the recursion depth reaches O(N).
// In a balanced tree, the recursion depth is O(log N).
// Hence, the worst-case space complexity is O(N), and for a balanced tree, it is O(log N).