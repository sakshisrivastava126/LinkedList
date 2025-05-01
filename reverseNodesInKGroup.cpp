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
       ListNode* findKNode(ListNode* head, int k) {
        while (head != NULL && k > 1) {
            head = head->next;
            k--;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = nullptr;
        ListNode* prevNode = nullptr;
        ListNode* KNode = nullptr;

        while(temp != NULL){
            KNode = findKNode(temp, k);   //finding Kth Node 
            if(KNode == NULL){            //if we are not able to find Kth Node
                if(prevNode){               //we check prev exist or not
                    prevNode->next = temp;    
                    break;
                }
              }    
                nextNode = KNode->next;     //store nextNode before pointing it to null
                KNode->next = NULL;
                reverse(temp);            //reverse the node
                
                if(temp == head){       //if it's first K nodes then we have to assign new head
                    head = KNode;
                }
                else{                  //else we will make prev node point to new head of new portion of LL
                    prevNode->next = KNode;
                }
                prevNode = temp;      //storing prevnode before changing the value of temp
                temp = nextNode;  
        }
        return head;
    }
};
