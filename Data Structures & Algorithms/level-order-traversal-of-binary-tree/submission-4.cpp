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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> levelNodes;
        levelNodes.push(root);

        while(!levelNodes.empty()) {
            int levelSize = levelNodes.size();

            vector<int> currentValues;
            currentValues.reserve(levelSize);
            
            for(int i = 0 ; i < levelSize ; i++) {
                TreeNode* currentNode = levelNodes.front();
                levelNodes.pop();

                if(currentNode->left) levelNodes.push(currentNode->left);
                if(currentNode->right) levelNodes.push(currentNode->right);

                currentValues.push_back(currentNode->val);
            }
            res.push_back(currentValues);
        }
        return res;
    }
};
