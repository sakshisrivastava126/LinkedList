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
    void deleteNode(ListNode* node) {
        //instead of deleting the node itself, copy the next node's data in the node 
        //and delete the next node 
        //this will make the current node act like next node 
        ListNode* temp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete(temp);
    }
};
