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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*curr=head;
       queue<int>pq;
          int sum=0;
        while(curr!=NULL){
      
            if(curr->val==0&&sum!=0) pq.push(sum);
            if(curr->val!=0) sum+=curr->val;
            if(curr->val==0) sum=0;
            curr=curr->next;
        }
        ListNode*ans=new ListNode(0);
        ListNode*p=ans;
        while(!pq.empty()){
        p->next=new ListNode(pq.front());
        pq.pop();
        p=p->next;}
        return ans->next;
    }
};