#include "../libs.hpp"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution2 {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;

        int leftH(0), rightH(0);
        TreeNode *l(root), *r(root);

        // Get Left & Right Depth (==Height)
        while(l) ++leftH, l = l->left;
        while(r) ++rightH, r = r->right;

        if(leftH == rightH)
            return (1 << leftH) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};


class Solution1 {
private:
    bool chkTree(TreeNode* root, int target)
    {
        int h = 1;
        while(h <= target)
            h *= 2;
        
        int layer = h/2;
        int t = target - layer;
        while(layer > 1)
        {
            layer /= 2;
            if(t/layer == 0)
                root = root->left;
            else
                root = root->right, t -= layer;
        }
        return (root != nullptr) && (root->val == target);
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        int leftH(1), rightH(1);
        TreeNode *l(root), *r(root);

        // Left Height
        while(l->left != nullptr)
            ++leftH, l = l->left;

        // Right Height
        while(r->right != nullptr)
            ++rightH, r = r->right;

        if(leftH == rightH)
            return pow(2, rightH) - 1;
        else
        {   // Range [2^rightH, 2^leftH) 
            // rightH + 1 == leftH;
            int l = pow(2, rightH);
            int r = pow(2, leftH) - 1;
            while(l < r)
            {
                int m = (l+r)/2;
                if(chkTree(root, m))
                    l = m + 1;
                else
                    r = m;
            }
            return (l==r)?(r-1):(-1);
        }
    }
};

int main()
{

    Solution2 S;
    return 0;
}