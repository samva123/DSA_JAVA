#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(Node* root) {
        vector<int> result;
        stack<Node*> st;
        Node* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left; // Move left as much as possible
            }

            Node* node = st.top(); // Assign a different name
            st.pop();
            result.push_back(node->data); // Process node

            curr = node->right; // Move to the right subtree
        }

        return result;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
