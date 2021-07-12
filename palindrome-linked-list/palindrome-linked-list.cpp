/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) return true;
		int n = 1; ListNode *Head = head;
        while(Head->next != nullptr)
        {
            n++;  Head = Head->next;
        }
            int i = 1;
           ListNode* p = head,*q,*t;
           q = p->next; t = q->next; p->next = nullptr;
           ListNode*head1 = q;
           ListNode*head2 = p;
           while(i != n/2)
           {
               t = q->next;
               q->next = p;
               p = q; q =t;
               head1 = q;head2 = p;
               i++;     
           }
           if(n%2 == 1) q = q->next;
           while(p!= nullptr)
           {
               if(p->val != q->val) return false;
               p = p->next;q = q->next;
           }
            return true;   
    }
};