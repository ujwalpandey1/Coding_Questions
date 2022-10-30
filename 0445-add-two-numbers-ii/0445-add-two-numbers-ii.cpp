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
    ListNode* reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*n=head->next;
        ListNode*prev=NULL;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=n;
            if(n!=NULL) n=n->next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode*p=reverse(l1);
        ListNode*q=reverse(l2);
        int sum=0;
        int carry=0;
        ListNode*ans=new ListNode(0);
        ListNode*curr=ans;
        while(p!=NULL||q!=NULL){
            int x=p!=NULL?p->val:0;
            int y=q!=NULL?q->val:0;
            sum=x+y+carry;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            if(p!=NULL)p=p->next;
           if(q!=NULL) q=q->next;
        }
        if(carry>0) curr->next=new ListNode(carry);
        return reverse(ans->next);
        
    }
};