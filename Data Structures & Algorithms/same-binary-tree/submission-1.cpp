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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> levelNodes;
        levelNodes.push({p, q});
        while(!levelNodes.empty()) {
            int levelSize = levelNodes.size();
            for(int i = 0 ; i < levelSize ; i++) {
                auto [pNode, qNode] = levelNodes.front();
                levelNodes.pop();

                if(!pNode && !qNode) continue;

                if(!pNode || !qNode || (pNode->val != qNode->val)) return false;

                levelNodes.push({pNode->left, qNode->left});
                levelNodes.push({pNode->right, qNode->right}); 
            }
        }
        return true;
    }
};
