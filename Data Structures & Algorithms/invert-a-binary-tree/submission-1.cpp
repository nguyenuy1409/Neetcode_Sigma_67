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

class Solution {
   public:
    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
                int levelSize = q.size();

                for(int i = 0 ; i < levelSize ; i++) {
                        TreeNode* currNode = q.front();
                        q.pop();

                        if(currNode->left) q.push(currNode->left);
                        if(currNode->right) q.push(currNode->right);
                        swap(currNode->left, currNode->right);
                }
        }
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        bfs(root);
        return root;
    }
};