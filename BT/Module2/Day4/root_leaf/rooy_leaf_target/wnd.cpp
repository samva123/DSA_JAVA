// #include <iostream>
// #include <unordered_map>
// #include <vector>
// #include <queue>

// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     bool getPath(TreeNode* root, vector<int>& arr, int x) {
//         if (!root) {
//             return false;
//         }

//         arr.push_back(root->val);

//         if (root->val == x) {
//             return true;
//         }

//         if (getPath(root->left, arr, x) || getPath(root->right, arr, x)) {
//             return true;
//         }

//         arr.pop_back();
//         return false;
//     }

//     vector<int> solve(TreeNode* A, int B) {
//         vector<int> arr;

//         if (A == NULL) {
//             return arr;
//         }

//         getPath(A, arr, B);
//         return arr;
//     }
// };

// int main() {
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(1);
//     root->left->left = new TreeNode(6);
//     root->left->right = new TreeNode(2);
//     root->right->left = new TreeNode(0);
//     root->right->right = new TreeNode(8);
//     root->left->right->left = new TreeNode(7);
//     root->left->right->right = new TreeNode(4);

//     Solution sol;

//     int targetLeafValue = 7;

//     vector<int> path = sol.solve(root, targetLeafValue);

//     cout << "Path from root to leaf with value " << targetLeafValue << ": ";
//     for (int i = 0; i < path.size(); ++i) {
//         cout << path[i];
//         if (i < path.size() - 1) {
//             cout << " -> ";
//         }
//     }

//     return 0;
// }




























// #include <iostream>
// #include <vector>
// #include <stack>
// #include <unordered_map>

// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode *left, *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     vector<int> solve(TreeNode* root, int target) {
//         if (!root) return {};

//         stack<pair<TreeNode*, vector<int>>> st;
//         st.push({root, {}});

//         while (!st.empty()) {
//             auto [node, path] = st.top();
//             st.pop();

//             path.push_back(node->val);
            
//             if (node->val == target) return path;

//             if (node->right) st.push({node->right, path});
//             if (node->left) st.push({node->left, path});
//         }

//         return {};
//     }
// };

// int main() {
//     TreeNode* root = new TreeNode(3);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(1);
//     root->left->left = new TreeNode(6);
//     root->left->right = new TreeNode(2);
//     root->right->left = new TreeNode(0);
//     root->right->right = new TreeNode(8);
//     root->left->right->left = new TreeNode(7);
//     root->left->right->right = new TreeNode(4);

//     Solution sol;
//     int targetLeafValue = 7;

//     vector<int> path = sol.solve(root, targetLeafValue);

//     cout << "Path from root to node " << targetLeafValue << ": ";
//     for (int i = 0; i < path.size(); ++i) {
//         cout << path[i] << (i < path.size() - 1 ? " -> " : "");
//     }

//     return 0;
// }



















#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> solve(TreeNode* root, int target) {
        if (!root) return {};

        queue<pair<TreeNode*, vector<int>>> q;
        q.push({root, {}});

        while (!q.empty()) {
            //auto [node, path] = q.front();
            auto front  = q.front();
            TreeNode* node  = front.first;
            auto path  = front.second;
            q.pop();

            path.push_back(node->val);
            
            if (node->val == target) return path;

            if (node->left) q.push({node->left, path});
            if (node->right) q.push({node->right, path});
        }

        return {};
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    int targetLeafValue = 7;

    vector<int> path = sol.solve(root, targetLeafValue);

    cout << "Path from root to node " << targetLeafValue << ": ";
    for (int i = 0; i < path.size(); ++i) {
        cout << path[i] << (i < path.size() - 1 ? " -> " : "");
    }

    return 0;
}
