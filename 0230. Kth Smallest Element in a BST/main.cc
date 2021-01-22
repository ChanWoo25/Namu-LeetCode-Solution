#include "../libs.hpp"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(p || !stk.empty())
        {
            while(p)
            {
                stk.push(p); 
                p = p->left;
            }

            p = stk.top(); stk.pop();
            if(--k == 0)
                return p->val;
            p = p->right;
        }
        return -1;
    }
};


// Using Circular Vector
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> Stack(k);
        
        int i(0), j(k);
        while(1)
        {
            while(root) 
            {
                Stack[(i++)%k] = root;
                root = root->left;
            }
            root = Stack[(--i)%k];
            if(!(--j))
                return root->val;
            root = root->right;
        }
        return -1;
    }
};

typedef struct NumTreeNode{
    int val;
    NumTreeNode *left, *right;
    NumTreeNode() : val(0), left(nullptr), right(nullptr) {}
    NumTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
} nTree;

class FailSolution {
private:    
    int numOfNodes(TreeNode* root, nTree* nroot)
    {
        if(!root)
            return 0;
        else
            nroot = new nTree();
        
        return nroot->val \
            = numOfNodes(root->left, nroot->left) \
            + numOfNodes(root->right, nroot->right) \
            + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        nTree *nroot = new nTree();
        numOfNodes(root, nroot);

        while(1)
        {
            if(k==1)
            {
                while(root->left)
                    root = root->left;
                return root->val;
            }
            else
            {
                if(nroot->left)
                {
                    if(k <= nroot->left->val){
                        root = root->left;
                        nroot = nroot->left;
                    }
                    else if(k == (nroot->left->val + 1))
                        return root->val;
                    else{
                        k -= (nroot->left->val + 1);
                        root = root->right;
                        nroot = nroot->right;
                    }
                }
                else 
                {
                    k -= 1;
                    root = root->right;
                    nroot = nroot->right;
                }
            }
        }

        return -1;
    }
};

int main()
{

    Solution1 S;
    return 0;
}