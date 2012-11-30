/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int priority = 0;
        ListNode* ret;
        ListNode* p_ret, *p_l1, *p_l2;
        p_l1 = l1;
        p_l2 = l2;
        p_ret = ret = new ListNode((p_l1->val+p_l2->val)%10);
        priority = (p_l1->val + p_l2->val) >=10 ?1:0; 
        p_l1 = p_l1->next;
        p_l2 = p_l2->next;
        while ( p_l1 && p_l2 ) {
            ListNode* tmp = new ListNode((priority+p_l1->val+p_l2->val)%10);
            priority = (priority + p_l1->val + p_l2->val) >=10 ?1:0;
            p_ret->next = tmp;
            p_ret = tmp;
            p_l1 = p_l1->next;
            p_l2 = p_l2->next;
        }
        while ( p_l1 ) {
            ListNode* tmp = new ListNode((priority+p_l1->val)%10);
            priority = (priority + p_l1->val) >=10 ?1:0;
            p_ret->next = tmp;
            p_ret = tmp;
            p_l1 = p_l1->next;
        }
        while ( p_l2 ) {
            ListNode* tmp = new ListNode((priority+p_l2->val)%10);
            priority = (priority + p_l2->val) >=10 ?1:0;
            p_ret->next = tmp;
            p_ret = tmp;
            p_l2 = p_l2->next;
        }
        if ( priority ) {
            ListNode* tmp = new ListNode(1);
            p_ret->next = tmp;
            p_ret = tmp;
        }
        return ret;
    }
};