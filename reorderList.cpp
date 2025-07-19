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
        if(head == NULL || head->next == NULL) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = head->next;

        while(curr != nullptr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        //calculating middle element
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        //reverse the list after mid
        ListNode* reversedHead = reverseList(mid);

        //now we have 2 list : head->mid & mid->end in reversed
        ListNode* list1 = head;
        ListNode* list2 = reversedHead;

        while(list1 != nullptr && list2 != nullptr){
            //store the next nodes of both LL
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            
            //merge
            list1->next = list2;
            //if next is null break loop
            if (temp1 == nullptr) break;
            list2->next = temp1;
            
            //update to the next values of list
            list1 = temp1;
            list2 = temp2;
        }
    }
};
