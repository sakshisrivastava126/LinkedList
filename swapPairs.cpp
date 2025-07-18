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
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;

        while(temp1 != nullptr && temp1->next != nullptr){
            temp2 = temp1->next;

            temp1->next = temp2->next;
            prev->next = temp2;
            temp2->next = temp1;

            prev = temp1;
            temp1 = temp1->next;
        }
        return dummy->next;
    }
};
