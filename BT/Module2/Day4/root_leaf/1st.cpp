// class Solution {
//     public:
    
//       void solve(Node* root,vector<vector<int>>&ans,vector<int>arr)
//       {
//           if(!root) return;
//           arr.push_back(root->data);
//           if(root->left==NULL&&root->right==NULL){
//               ans.push_back(arr);
//               return;
//           }
          
//           solve(root->left,ans,arr);
//           solve(root->right,ans,arr);
//       }  
//       vector<vector<int>> Paths(Node* root) {
//           vector<vector<int>>ans;
          
          
//           vector<int>arr;
//           solve(root,ans,arr);
//           return ans;
//       }
//   };







#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> Paths(Node* root) {
        if (!root) return {};
        
        vector<vector<int>> ans;
        stack<pair<Node*, vector<int>>> st;
        st.push({root, {}});

        while (!st.empty()) {
            auto front  = st.top();
            Node* node  = front.first;
            auto path  = front.second;
            st.pop();

            path.push_back(node->data);

            if (!node->left && !node->right) {
                ans.push_back(path);
                continue;
            }

            if (node->right) st.push({node->right, path});
            if (node->left) st.push({node->left, path});
        }

        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    for (auto& path : paths) {
        for (int val : path) cout << val << " ";
        cout << endl;
    }

    return 0;
}











#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> Paths(Node* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        queue<pair<Node*, vector<int>>> q;
        q.push({root, {}});

        while (!q.empty()) {
            auto front  = q.front();
            Node* node  = front.first;
            auto path  = front.second;
            q.pop();

            path.push_back(node->data);

            if (!node->left && !node->right) {
                ans.push_back(path);
                continue;
            }

            if (node->left) q.push({node->left, path});
            if (node->right) q.push({node->right, path});
        }

        return ans;
    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<vector<int>> paths = sol.Paths(root);

    for (auto& path : paths) {
        for (int val : path) cout << val << " ";
        cout << endl;
    }

    return 0;
}
