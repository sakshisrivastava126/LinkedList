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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

//COMPARING LEN APPROACH : TAKES MORE TIME : Not good approach
    //     int len1=0;
    //     int len2 = 0;
    //     ListNode* ansNode;
    //     ListNode* t1 = l1;
    //     ListNode* t2 = l2;
    //     ListNode* prev = nullptr;
    //     int carry = 0;

//check length of each LL
    //     while(t1 != NULL){     
    //         len1++;
    //         t1 = t1->next;
    //     }

    //     while(t2 != NULL){
    //         len2++;
    //         t2 = t2->next;
    //     }
    //COMPARE lens, the one which is longer we'll use that one to store ans
    //     if(len1 >= len2){
    //         t1 = l1;
    //         t2 = l2;
    //         ansNode = l1;
    //     }
    //     else{
    //         t1 = l2;
    //         t2 = l1;
    //         ansNode = l2;
    //     }

    //traverse through the one which is shorter
    //     while(t2 != NULL){
    //         t1->val = t1->val + t2->val + carry;
    //             carry = t1->val/10;
    //             t1->val = t1->val%10;
    //          prev = t1;
    //         t1 = t1->next;
    //         t2 = t2->next;
    //     }
    
    //traverse the rest of the part the one which is longer
    //         while(t1 != NULL){
    //             t1->val = t1->val + carry;
    //             carry = t1->val/10;
    //             t1->val = t1->val%10;
    //            prev = t1;
    //            t1 = t1->next;
    //         }

    //if carry is still left, create new node and add to LL
    //   if (carry != 0) {
    //         prev->next = new ListNode(carry);
    //     }
    //     return ansNode;

//OPTIMIZED APPROACH USING DUMMYNODE
      ListNode* dummyNode = new ListNode(-1);
      ListNode* t1 = l1;
      ListNode* t2 = l2;
      ListNode* curr = dummyNode;
      int carry = 0;
      int sum = 0;

     //traverse through both LL and keep of adding new nodes
      while(t1 != NULL || t2 != NULL){
        sum = carry;
        if(t1) sum += t1->val;
        if(t2) sum += t2->val;

        ListNode* newNode = new ListNode(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
      }

      //after both LL's traversal if carry still exist, create new node for it and add to LL
      if(carry) curr->next = new ListNode(carry);

      return dummyNode->next;
    }
};
