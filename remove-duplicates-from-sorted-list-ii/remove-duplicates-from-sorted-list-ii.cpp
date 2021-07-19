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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        
        unordered_map<int, bool> isRepeated;
        ListNode *temp = head;
        ListNode *temp2 = head;
        while(temp){
            while(temp->next && temp ->next ->val == temp ->val){
                isRepeated[temp->val] = 1;
                temp ->next = temp->next->next;
            }
            temp = temp->next;
        }
        // while(temp2 && temp2->next){
        //     if(isRepeated[temp2->val]){
        //         temp2->next = temp->next->next;
        //     }
        // }
        while(temp2->next){
            if(isRepeated[temp2->next->val])
                temp2->next = temp2->next->next;
            else
            temp2 = temp2->next;
        }
        if(isRepeated[head->val])
            head = head->next;
        return head;
        
    }
};