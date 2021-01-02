/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> q;
        if(cloned->val == target->val)
            return cloned;
        
        q.push(cloned);
        while(!q.empty())
        { 
            TreeNode* e = q.front();
            q.pop();
            
            if(e->left)
            {
                if(e->left->val == target->val)
                    return e->left;
                else
                    q.push(e->left);
            }
            if(e->right)
            {
                if(e->right->val == target->val)
                    return e->right;
                else
                    q.push(e->right);
            }
        }
        
        return nullptr;
    }
};
