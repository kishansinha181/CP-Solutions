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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* next;
        ListNode* curr=head;
        while(curr && curr->next){
            next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = curr;
            curr=curr->next;
        }
        return dummy->next;
        
    }
};