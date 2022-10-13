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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode*curr=root;
       while(curr){

       if(curr->left){
           TreeNode*pred=curr->left;
           TreeNode*temp=curr->left;
           while(pred->right) pred=pred->right;
           pred->right=curr;
           curr->left=NULL;
           curr=temp;
       }
           else {
               k--;
               if(k==0) return curr->val;
               curr=curr->right;
           }
       }
        return 0;
    }
};