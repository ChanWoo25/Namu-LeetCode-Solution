#include "../libs.hpp"


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *p1, *p2(head);
        for(auto p = head; p != nullptr; p = p->next)
        {
            if(--k == 0){
                p1 = p2;
                p2 = head;
            }
            else
                p2 = p2->next;
        }      
        swap(p1->val, p2->val);
        return head;
    }
};

int main()
{

    Solution S;
    return 0;
}