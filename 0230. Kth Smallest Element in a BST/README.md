### 230. Kth Smallest Element in a BST

**Time Complexity** : $O(N)$

**Space Complexity** : $O(k)$

#### Description

- 왼쪽 자식에 속하는 모든 노드는 현재 노드보다 작은 값을 갖고,
- 오른쪽 자식 속하는 모든 노드는 현재 노드보다 큰 값을 갖는 Binary Search이기에
- 다음과 같은 방법으로 k-th element를 쉽게 탐색할 수 있다.
  1. leftmost child는 Tree의 가장 작은 값이다.
  2. 만약 왼쪽 child의 모든 노드와 현재 노드가 kth smallest를 만족하지 않으면, **right child**로 넘어가 1,2.를 똑같이 수행한다.
  3. right child에 속한 노드를 모두 검사하면, 직전 **1.** Step의 Stack에 쌓았던 다음 left child를 검사한다.

**Solution1:** stack을 이용하여 해결
**Solution2:** kth-smallest에 필요한 k개의 배열만을 유지하여 공간을 절약한다. 

```cpp
class Solution1 {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* p = root;
        while(p || !stk.empty())
        {
            // p가 있는 경우, Left-most child까지 스택에 넣는 역할.
            // 그리하여 넣어진 p들은 이전 스택에 들어있던 두 Element의 중간 구간의 모든 원소를 검사하게 된다.
            while(p)
            {
                stk.push(p); 
                p = p->left;
            }

            // 스택에서 뽑아내어 검사하는 부분
            p = stk.top(); stk.pop();
            if(--k == 0)
                return p->val;

            // right child가 있는 경우, Stack에 고려하기 위해.
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
```

#### Follow-up
- 만약 Tree에 지속적으로 원소가 추가될 수 있다면,
- 어떻게 더 효율적으로 관리할 수 있을까?

```cpp
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
```