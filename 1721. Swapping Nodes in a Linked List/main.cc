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
        ListNode *curr = head, *kth, *k1th, *nkth, *nk1th;
        int idx = 1, sz;

        if(k==1) {
            kth = head;
            k1th = nullptr;
        }
        while(curr->next != nullptr){
            if(idx == k-1){
                k1th = curr;
                kth = curr->next;
            }
            curr = curr->next;
            idx++;
        }
        sz = idx;
        int nk = sz - k + 1;
        curr = head; idx = 1;
        if(nk==1) {
            nkth = head;
            nk1th = nullptr;
        }
        while(curr->next != nullptr){
            curr = curr->next;
            idx++;
            if(idx == nk-1){
                nk1th = curr;
                nkth = curr->next;
            }
        }

        if(k1th == nullptr)
        {
            if(nk1th == nullptr)
            {
                return head;
            }
            else
            {
                ListNode* tmp = nkth->next;
                nk1th->next = kth;
                nkth->next = kth->next;
                kth->next = tmp;
                head = nkth;
            }
        }
        else
        {
            if(nk1th == nullptr)
            {
                ListNode* tmp = kth->next;
                k1th->next = nkth;
                kth->next = nkth->next;
                nkth->next = tmp;
                head = kth;
            }
            else
            {
                nk1th->next = kth;
                k1th->next = nkth;
                ListNode* tmp = kth->next;
                kth->next = nkth->next;
                nkth->next = tmp;
            }
        }
        return head;
    }
};

int main()
{

    Solution S;
    return 0;
}