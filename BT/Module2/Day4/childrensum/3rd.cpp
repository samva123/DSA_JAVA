#include <queue>

class Solution {
public:
    int isSumProperty(Node* root) {
        if (!root) return 1;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            int childSum = 0;
            if (node->left) {
                childSum += node->left->data;
                q.push(node->left);
            }
            if (node->right) {
                childSum += node->right->data;
                q.push(node->right);
            }

            if ((node->left || node->right) && node->data != childSum)
                return 0;
        }

        return 1;
    }
};
