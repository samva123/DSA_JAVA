#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;

        stack<pair<Node*, int>> s;
        s.push({root, 1});
        int maxDepth = 0;

        while (!s.empty()) {
            // auto [node, depth] = s.top();
            pair<Node*, int> temp = s.top();
            Node* node = temp.first;
            int depth = temp.second;

            s.pop();
            maxDepth = max(maxDepth, depth);

            // Push right child first, so left is processed first (mimicking recursion)
            if (node->right) s.push({node->right, depth + 1});
            if (node->left) s.push({node->left, depth + 1});
        }

        return maxDepth;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;
    cout << "Maximum depth (Iterative DFS using stack): " << solution.maxDepth(root) << endl;

    return 0;
}







#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0;

        queue<Node*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int size = q.size();
            depth++; // Increase depth level

            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return depth;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;
    cout << "Maximum depth (BFS using queue): " << solution.maxDepth(root) << endl;

    return 0;
}




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
//     public:
//         int maxDepth(TreeNode* root) {
//             if(root == NULL){
//                 return 0;
//             }
    
//             int lh = maxDepth(root->left);
//             int rh = maxDepth(root->right);
    
//             return max(lh , rh)+1;
            
//         }
//     };



// 🔹 Summary of Time & Space Complexity
// Approach	Time Complexity	Space Complexity (Balanced)	Space Complexity (Skewed)
// Recursive DFS	O(N)	O(log N)	O(N)
// BFS (Queue)	O(N)	O(N)	O(N)
// Iterative DFS (Stack)	O(N)	O(log N)	O(N)
// 🔥 Key Takeaways
// All three approaches have the same time complexity: O(N).
// DFS (Recursive & Iterative) is more space-efficient in a balanced tree: O(log N).
// BFS is always O(N) in space, making it less efficient for large trees.
// Recursive DFS can cause stack overflow in a skewed tree, where iterative DFS is preferred.
// Would you like a recommendation based on a specific scenario? 🚀