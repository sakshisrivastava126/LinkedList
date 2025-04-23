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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {

        //tortoise & hare method for SPLITTING THE LL IN TWO PARTS ie MIDDLE
       ListNode* slow = head;
       ListNode* fast = head;
       while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
       }

       //REVERSE 2ND HALF LL
       ListNode* newHead = reverse(slow->next);

       //COMPARE 1ST HALF WITH 2ND HALF
       ListNode* first = head;
       ListNode* second = newHead; 

       while(second != NULL){
        if(first->val != second->val){
            reverse(newHead);     //DON'T FORGET TO REVERSE BACK TO ORIGINAL THE 2ND HALF BEFORE GIVING ANS
            return false;
        }
        first = first->next;    
        second = second->next;
       }
       reverse(newHead);
       return true;
    }
};
