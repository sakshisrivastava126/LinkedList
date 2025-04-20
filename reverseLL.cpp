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
    ListNode* reverseList(ListNode* head) {
        //NORMAL METHOD : using iteration
        // if(head == NULL || head->next == NULL) return head;
        // ListNode* temp = head;
        // ListNode* front = NULL;
        // ListNode* prev = NULL;
        // while(temp != NULL){
        //     front = temp->next;  //trick is to store the front of temp before u change it
        //     temp->next = prev;
        //     prev = temp;
        //     temp = front;
        // }
        // return prev;

        //RECURSIVE METHOD
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};
