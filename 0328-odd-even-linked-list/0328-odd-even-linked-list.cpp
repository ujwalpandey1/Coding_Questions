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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode*even=new ListNode(0);
        ListNode*odd=new ListNode(0);
        ListNode*curr=head;
        ListNode*e=even;
        ListNode*o=odd;
        
        while(curr!=NULL&&curr->next!=NULL){
          e->next=new ListNode(curr->val);
            curr=curr->next;
            curr=curr->next;
              
            e=e->next;
            
        }
        if(curr!=NULL) {e->next=new ListNode(curr->val); e=e->next;}
        ListNode*cur=head->next;
      
         while(cur!=NULL&&cur->next!=NULL){
           o->next=new ListNode(cur->val);
            cur=cur->next;
            cur=cur->next;
              
            o=o->next;
            
        }
        if(cur!=NULL) {o->next=new ListNode(cur->val); o=o->next;}
        e->next=odd->next;
   return even->next;
        
    }
};