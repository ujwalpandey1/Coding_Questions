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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flag=false;
    bool solve(TreeNode*root,ListNode*head){
        if(head==NULL) return true;
        if(root==NULL)return false;
        return (root->val==head->val)&&(solve(root->left,head->next)||solve(root->right,head->next));
        
    }
    void solve2(ListNode* head, TreeNode* root){
        if(root==NULL) return;
        if(solve(root,head)) flag=true;
        solve2(head,root->left);
        solve2(head,root->right);
        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        TreeNode*curr=root;
        ListNode*h=head;
        solve2(h,curr);
        return flag;
    }
};