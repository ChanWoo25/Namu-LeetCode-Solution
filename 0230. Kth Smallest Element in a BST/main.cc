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

// public class Solution {
//     public int kthSmallest(TreeNode root, int k) {
//         TreeNodeWithCount rootWithCount = buildTreeWithCount(root);
//         return kthSmallest(rootWithCount, k);
//     }
    
//     private TreeNodeWithCount buildTreeWithCount(TreeNode root) {
//         if (root == null) return null;
//         TreeNodeWithCount rootWithCount = new TreeNodeWithCount(root.val);
//         rootWithCount.left = buildTreeWithCount(root.left);
//         rootWithCount.right = buildTreeWithCount(root.right);
//         if (rootWithCount.left != null) rootWithCount.count += rootWithCount.left.count;
//         if (rootWithCount.right != null) rootWithCount.count += rootWithCount.right.count;
//         return rootWithCount;
//     }
    
//     private int kthSmallest(TreeNodeWithCount rootWithCount, int k) {
//         if (k <= 0 || k > rootWithCount.count) return -1;
//         if (rootWithCount.left != null) {
//             if (rootWithCount.left.count >= k) return kthSmallest(rootWithCount.left, k);
//             if (rootWithCount.left.count == k-1) return rootWithCount.val;
//             return kthSmallest(rootWithCount.right, k-1-rootWithCount.left.count);
//         } else {
//             if (k == 1) return rootWithCount.val;
//             return kthSmallest(rootWithCount.right, k-1);
//         }
//     }
    
//     class TreeNodeWithCount {
//         int val;
//         int count;
//         TreeNodeWithCount left;
//         TreeNodeWithCount right;
//         TreeNodeWithCount(int x) {val = x; count = 1;};
//     }
// }


class Solution {
private:    
    typedef struct TreeWithNodeCount{
        int val, count;
        TreeWithNodeCount *left, *right;
        TreeWithNodeCount() : val(0), count(1), left(nullptr), right(nullptr) {}
        TreeWithNodeCount(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
        TreeWithNodeCount(int x, TreeWithNodeCount* l, TreeWithNodeCount* r) 
            : val(x), count(1), left(l), right(r) {}
    } nTree;

    nTree* buildnTree(TreeNode* root)
    {
        if(!root)
            return nullptr;
        
        nTree* curr = new nTree(root->val, 
                                buildnTree(root->left), 
                                buildnTree(root->right));
        
        curr->count += (curr->left)?(curr->left->count):0;
        curr->count += (curr->right)?(curr->right->count):0;
        return curr;
    }

    // Class's root nTree
    nTree* nRoot;

public:
    int findKthSmallest(nTree* root, int k)
    {
        // Size Exception
        if(k <= 0 || root->count < k) return -1;

        if(root->left)
        {
            int leftNodes = root->left->count;
            if(k <= leftNodes)
                return findKthSmallest(root->left, k);
            else if(k-1 == leftNodes)
                return root->val;
            else
                return findKthSmallest(root->right, k-1-leftNodes);
        }
        else
        {
            if(k == 1)
                return root->val;
            else
                return findKthSmallest(root->right, k-1);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        nRoot = buildnTree(root);
        return findKthSmallest(nRoot, k);
    }

    // We don't consider 
    // the case that redundunt e aleady exists in nRoot.
    void addNewNode(int e)
    {
        if(!nRoot){
            cout << "Make nRoot First!" << endl;
            return;
        }

        nTree* p = nRoot;
        while(p)
        {
            if(p->val < e){
                p->count++;
                p = p->right;
            }
            else{
                p->count++;
                p = p->left;
            }
        }
        p = new nTree(e);
    }
};

int main()
{

    Solution1 S;
    return 0;
}