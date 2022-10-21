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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>list;
        for(int i=0;i<lists.size();i++){
            ListNode*cur=lists[i];
            while(cur){
                list.push_back(cur->val);
                cur=cur->next;
            }
        }
        sort(list.begin(),list.end());
        ListNode*ans=new ListNode(0);
        ListNode*curr=ans;
        int i=0;
        while(i<list.size()){
            curr->next=new ListNode(list[i]);
            curr=curr->next;
            i++;
        }
      
        return ans->next;
    }
};