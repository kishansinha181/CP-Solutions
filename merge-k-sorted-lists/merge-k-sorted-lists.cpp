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
struct cmp {
        bool operator()(ListNode* l1,ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto x:lists){
            if(x!=NULL) pq.push(x);
        }
        if(pq.size()==0) return NULL;
        ListNode* res = new ListNode();
        ListNode* ptr = res;
        while(pq.size()!=0){
            ListNode* temp = pq.top();
            pq.pop();
            res->next = temp;
            res = res->next;
            if(temp->next!=NULL){
                pq.push(temp->next);
            }
        }
        return ptr->next;
    }
};