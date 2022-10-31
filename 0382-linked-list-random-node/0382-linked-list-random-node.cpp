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
    vector<int>ans;
    int i=0;
    
    Solution(ListNode* head) {
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
            i++;
        }
    }
    
    int getRandom() {
       int x;
       return ans[rand()%i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */