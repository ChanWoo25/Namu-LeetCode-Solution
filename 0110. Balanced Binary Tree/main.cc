#include "../libs.hpp"
#define null int(-1e8)

struct TreeNode { 
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode() : val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
}; 

// Bottom Up Approach 
// Space Complexity: O(N), Time Complexity: O(N) 
class MySolution { 
public: 
    bool flag = true; 
    int chkNode(TreeNode* curr, int layer) 
    { 
        if(curr == nullptr) 
            return layer - 1; 
        int l = chkNode(curr->left, layer+1); 
        int r = chkNode(curr->right, layer+1); 
         
        if(abs(l-r) > 1) 
            flag = false; 
         
        return (l>r)?l:r; 
    } 
    bool isBalanced(TreeNode* root) { 
        if(root == nullptr) 
            return true; 
         
        chkNode(root, 1); 
        return flag; 
    } 
}; 

void makeTree(TreeNode *root, int idx, const vector<int> &v) 
{ 
    int l = 2 * idx; 
    int r = l + 1; 
    if(l <= v.size() && v[l-1] != null) 
    {   // Left Node 
        root->left = new TreeNode(v[l-1]); 
        cout << "register Left  : " << v[l-1] << endl; 
        makeTree(root->left, l, v); 
    } 
    if(r <= v.size() && v[r-1] != null) 
    {   // Left Node 
        root->right = new TreeNode(v[r-1]); 
        cout << "register Right : " << v[r-1] << endl; 
        makeTree(root->right, r, v); 
    } 
    return; 
} 

class GoodSolution { 
public: 
    bool isBalanced(TreeNode* root) { 
        if(root == nullptr) 
            return true; 
        return height(root) != -1; 
    } 
    // root를 기준으로 Balanced Tree이면 0이상의 정수 반환, 그렇지 않으면 -1반환. 
    // Recursive하게 자식이 없는 노드부터 0, 1, 2의 값이 내려오도록 구현.
    int height(TreeNode* root){ 
        if(root == nullptr){ 
            return 0; 
        } 
        int lHeight = height(root->left); 
        int rHeight = height(root->right); 
        if(lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1){ 
            return -1; 
        } 
        return 1 + max(lHeight, rHeight); 
    } 
};

int main(){ 
    ios_base::sync_with_stdio(false); 
    cout << fixed << setprecision(12); 
    cin.tie(nullptr); 
    // INPUT 
    GoodSolution Sol; 
    vector<int> v = {3,9,20,null,null,15,7}; 
    TreeNode *root = (v.size() > 0)? \ 
    new TreeNode(v[0]):nullptr; 
    if(root != nullptr) 
        makeTree(root, 1, v); 
    cout << Sol.isBalanced(root) << endl; 
    return 0; 
}