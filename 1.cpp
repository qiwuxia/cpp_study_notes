#include <iostream>



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* lenptr = nullptr;
        lenptr = head;

        while(lenptr  == nullptr)
        {
            len++;
            lenptr = lenptr->next;
        }
        for (int i = 0; i<len-k; i+=k)
        {
            for (int j = 0;j<k/2;j++)
            {
                swap(head[i+j].val,head[i+k-j-1].val);
            }
        }
        return head;
    }
};