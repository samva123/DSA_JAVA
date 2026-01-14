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



// import java.util.*;

// class Solution {
    
//     public void solve(Node root, List<List<Integer>> ans, List<Integer> path) {
//     if (root == null) return;

//     path.add(root.data);

//     if (root.left == null && root.right == null) {
//         ans.add(path);  // no need to copy — it's unique at this point
//         return;
//     }

//     // Copy only when recursing
//     solve(root.left, ans, new ArrayList<>(path));
//     solve(root.right, ans, new ArrayList<>(path));
// }

    
//     public List<List<Integer>> Paths(Node root) {
//         List<List<Integer>> ans = new ArrayList<>();
//         solve(root, ans, new ArrayList<>());
//         return ans;
//     }
// }







// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int x) : data(x), left(nullptr), right(nullptr) {}
// };

// class Solution {
// public:
//     vector<vector<int>> Paths(Node* root) {
//         if (!root) return {};
        
//         vector<vector<int>> ans;
//         stack<pair<Node*, vector<int>>> st;
//         st.push({root, {}});

//         while (!st.empty()) {
//             auto front  = st.top();
//             Node* node  = front.first;
//             auto path  = front.second;
//             st.pop();

//             path.push_back(node->data);

//             if (!node->left && !node->right) {
//                 ans.push_back(path);
//                 continue;
//             }

//             if (node->right) st.push({node->right, path});
//             if (node->left) st.push({node->left, path});
//         }

//         return ans;
//     }
// };

// int main() {
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);
//     root->right->left = new Node(6);
//     root->right->right = new Node(7);

//     Solution sol;
//     vector<vector<int>> paths = sol.Paths(root);

//     for (auto& path : paths) {
//         for (int val : path) cout << val << " ";
//         cout << endl;
//     }

//     return 0;
// }





///////////////////////////////////IN JAVA/////////////////

// import java.util.*;

// class Node {
//     int data;
//     Node left, right;

//     Node(int data) {
//         this.data = data;
//     }
// }

// class Solution {
//     public List<List<Integer>> Paths(Node root) {
//         if (root == null) return new ArrayList<>();

//         List<List<Integer>> ans = new ArrayList<>();
//         Stack<Pair> stack = new Stack<>();
//         stack.push(new Pair(root, new ArrayList<>()));

//         while (!stack.isEmpty()) {
//             Pair front = stack.pop();
//             Node node = front.node;
//             List<Integer> path = new ArrayList<>(front.path); // clone the path
//             path.add(node.data);

//             if (node.left == null && node.right == null) {
//                 ans.add(path);
//                 continue;
//             }

//             if (node.right != null) stack.push(new Pair(node.right, path));
//             if (node.left != null) stack.push(new Pair(node.left, path));
//         }

//         return ans;
//     }

//     static class Pair {
//         Node node;
//         List<Integer> path;

//         Pair(Node node, List<Integer> path) {
//             this.node = node;
//             this.path = path;
//         }
//     }
// }





// import java.util.*;

// class Node {
//     int data;
//     Node left, right;

//     Node(int data) {
//         this.data = data;
//     }
// }

// class Solution {
//     public List<List<Integer>> Paths(Node root) {
//         if (root == null) return new ArrayList<>();

//         List<List<Integer>> ans = new ArrayList<>();
//         Stack<Pair> stack = new Stack<>();
//         stack.push(new Pair(root, new ArrayList<>())); // Start with empty path

//         while (!stack.isEmpty()) {
//             Pair front = stack.pop();
//             Node node = front.node;
//             List<Integer> path = front.path;

//             path.add(node.data); // Modify current path

//             if (node.left == null && node.right == null) {
//                 ans.add(path); // Final path added directly
//                 continue;
//             }

//             if (node.right != null) {
//                 stack.push(new Pair(node.right, new ArrayList<>(path)));
//             }

//             if (node.left != null) {
//                 stack.push(new Pair(node.left, new ArrayList<>(path)));
//             }
//         }

//         return ans;
//     }

//     static class Pair {
//         Node node;
//         List<Integer> path;

//         Pair(Node node, List<Integer> path) {
//             this.node = node;
//             this.path = path;
//         }
//     }

//     public static void main(String[] args) {
//         // Create the tree structure
//         Node root = new Node(1);
//         root.left = new Node(2);
//         root.right = new Node(3);
//         root.left.left = new Node(4);
//         root.left.right = new Node(5);
//         root.right.right = new Node(6);
//         root.left.right.left = new Node(7);
        
//         Solution sol = new Solution();
//         List<List<Integer>> paths = sol.Paths(root);

//         // Print all paths
//         System.out.println("All root-to-leaf paths:");
//         for (List<Integer> path : paths) {
//             System.out.println(path);
//         }
//     }
// }










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
