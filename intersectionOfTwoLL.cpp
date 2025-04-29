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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = 0;
        int n2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if(headA == NULL || headB == NULL ) return NULL;
        if(headA == headB) return headA;

//count both no. of nodes in each LL 
        while(temp1 != NULL){
            n1++;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            n2++;
            temp2 = temp2->next;
        }

//set back both temp to heads
        temp1 = headA;
        temp2 = headB;

//now, we'll move the Longer LL by the diff of nodes of two LL so they are vertically at same line
        if(n1>n2) {
            for(int i=0; i<n1-n2; i++){
                temp1 = temp1->next;
            }
        }
        if(n1<n2) {
            for(int i=0; i<n2-n1; i++){
                temp2 = temp2->next;
            }
        }
        
// now we'll move by 1 each LL and compare        
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
