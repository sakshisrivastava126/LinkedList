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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;

//BRUTEFORCE SOLN
        // ListNode* temp = head;
        // int cnt =0;
        // while(temp != NULL){
        //     cnt++;
        //     temp = temp->next;
        // }
        // if(cnt == n){
        //     ListNode* newHead = head->next;
        //     free(head);
        //     return newHead;
        // }
        // int pos = cnt - n;
        // temp = head;
        // cnt = 1;
        // while(temp != NULL){
        //     if(cnt == pos) break;
        //     temp = temp->next;
        //     cnt++;
        // }
        // temp->next = temp->next->next;
        // return head;

//OPTIMIZED
    ListNode* fast = head;
    ListNode* slow = head;

    for(int i =0; i<n; i++){     //move fast by n
        fast = fast->next;
    }

    if(fast == NULL) {          //handle case when we have to delete head 
        ListNode* newHead = head->next;
        delete(head);
        return newHead;
    }

    while(fast->next != NULL){   //then move both slow fast together
        slow = slow->next;
        fast = fast->next;
    }
    
    ListNode* delNode = slow->next;     //finally delete
    slow->next = slow->next->next;
    delete(delNode);
    return head;
    }
};
