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
        int len=0;
        ListNode*curr=head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        curr=head;
     
       
        if(len==n) return head->next;
        int k=len-n;
        int i=1;
        while(i<k){
            curr=curr->next;
            i++;
        }
        if(curr->next==NULL) return NULL;
        else if(curr->next->next==NULL) curr->next=NULL;
        else{
            curr->next=curr->next->next;
        }
        return head;
    }
};