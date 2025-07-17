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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        while(temp != nullptr && temp->next != nullptr){
            if(temp->val == temp->next->val){
                //skip krdo sari values jo same ho
                while(temp->next != nullptr && temp->val == temp->next->val){
                    temp = temp->next;
                }
                //agar skip krdiya toh finally temp and prev k next ki value change
                temp = temp->next;
                prev->next = temp;
            }
            else{
            temp = temp->next;
            prev = prev->next;
            //yaha ho skta h temp null hogya ho isliye while condition me check kro
            //always ki nullptr toh ni hua temp
            }
        }
        return dummy->next;
    }
};
