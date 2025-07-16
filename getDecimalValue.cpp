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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int cnt = 0;
        int res=0;
        //count krliya size of LL
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        cnt = cnt-1;
        temp = head;
        //pow calculate kr k add
        while(temp != NULL){
            if(temp->val == 1){
                res += pow(2, cnt);
            }
            cnt--;
            temp = temp->next;
        }
        return res;
    }
};
