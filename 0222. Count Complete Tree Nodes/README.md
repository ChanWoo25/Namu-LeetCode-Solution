### 222. Count Complete Tree Nodes

Given the root of **a complete binary tree**, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

**Constraints:**
- The number of nodes in the tree is in the range `[0, 5 * 104]`.
- `0 <= Node.val <= 5 * 10^4`
- The tree is guaranteed to be complete.
 
Follow up: Traversing the tree to count the number of nodes in the tree is an easy solution but with O(n) complexity. Could you find a faster algorithm?

**Time Complexity** : $O(lgN*lgN)$

**Space Complexity** : $O(lgN)$

**Description**

- 노드의 개수를 구하는 문제
- A complete binary tree라고 했고, 노드는 가능한 왼쪽 자식부터 가진다.
- 최대 $5*10^{4}$이기 떄문에 Brute Force로 검사하면 푸는 것은 간단.
- Binary Search 를 응용할 수 있을까? -> Solution
  - `LeftMost`와 `RightMost`를 검사
    - 만약 같으면, 정답 도출 가능
    - 다르면, 1차 범위 산정 후, *계속*
  - 1차 산정 범위 `[1, N]`이 있을 때, `2/N`이 있는지 검사
  - 재귀적으로 rightNode와 leftNode를 countNodes로 검사.
    - Complete Binary Tree이기 때문에 필연적으로 한쪽 노드는 O(1)에 결과 얻음.
  - 최대 lgN 번 재귀를 타고 들어감 + 각각 lgN만큼의 left&right Depth 비교 연산있음.


```cpp
class Solution {
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
```