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
    void bfs(TreeNode* root, vector<vector<int>>& res) {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int levelSize = q.size();
            vector<int> currVal;

            for(int i = 0 ; i < levelSize ; i++) {
                TreeNode* currNode = q.front();
                q.pop();

                currVal.push_back(currNode->val);
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
            res.push_back(currVal);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        bfs(root, res);
        return res;
    }
};
