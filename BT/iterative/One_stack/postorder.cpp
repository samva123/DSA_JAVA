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

// Function to return the postOrder traversal of a binary tree using one stack
vector<int> postOrder(Node* root) {
    vector<int> postorder;
    if (root == nullptr) return postorder;

    stack<Node*> st;
    Node* lastVisited = nullptr;  // Pointer to track the last visited node

    while (!st.empty() || root != nullptr) {
        // Traverse left and push all left nodes to stack
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }

        Node* node = st.top();

        // If the right child exists and hasn't been visited, move right
        if (node->right != nullptr && node->right != lastVisited) {
            root = node->right;
        } else {
            // If right is already visited, process the current node
            st.pop();
            postorder.push_back(node->data);
            
            lastVisited = node;
        }
    }

    return postorder;
}

// Function to print the elements of a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> result = postOrder(root);

    cout << "Postorder traversal: ";
    printVector(result);

    return 0;
}
