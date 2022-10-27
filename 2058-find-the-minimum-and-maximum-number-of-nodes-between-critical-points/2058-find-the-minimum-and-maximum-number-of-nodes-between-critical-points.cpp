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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode*curr=head->next;
        ListNode*prev=head;
        ListNode*n=head->next->next;
        vector<int>ans;
        vector<int>blank={-1,-1};
        vector<int>res;
        int len=0;
        while(n!=NULL){
            if((curr->val>prev->val&&curr->val>n->val)||(curr->val<prev->val&&curr->val<n->val))
                ans.push_back(len);
            prev=curr;
            curr=n;
            n=n->next;
            len++;
        }
        if(ans.size()<2) return blank;
        sort(ans.begin(),ans.end());
        int mini=INT_MAX;
        int maxi=ans[ans.size()-1]-ans[0];
        for(int i=0;i<ans.size()-1;i++){
            mini=min(mini,ans[i+1]-ans[i]);
        }
        res.push_back(mini);
        res.push_back(maxi);
        return res;
    }
};