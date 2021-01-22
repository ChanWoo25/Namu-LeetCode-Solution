### 230. Kth Smallest Element in a BST

**Time Complexity** : $O(N)$

**Space Complexity** : $O(k)$

#### Description

- 왼쪽 자식에 속하는 모든 노드는 현재 노드보다 작은 값을 갖고,
- 오른쪽 자식 속하는 모든 노드는 현재 노드보다 큰 값을 갖는 Binary Search이기에
- 다음과 같은 방법으로 k-th element를 쉽게 탐색할 수 있다.
  1. leftmost child는 Tree의 가장 작은 값이다.
  2. 만약 왼쪽 child의 모든 노드와 현재 노드가 kth smallest를 만족하지 않으면, \right child로 넘아가 1,2.를 똑같이 수행한다.
  3. right child에 속한 노드를 모두 검사하면, 1.에서 Stack에 쌓았던 다음 left child를 검사한다.

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
```