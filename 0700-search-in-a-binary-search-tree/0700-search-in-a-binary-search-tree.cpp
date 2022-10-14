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
 
    TreeNode*pre=NULL;
    
    void search(TreeNode*curr,int val){
        if(curr==NULL) return;
        if(curr->val==val){
            pre=curr;
        }
        search(curr->left,val);
        search(curr->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
      TreeNode*curr=root;
        search(curr,val);
       return pre;
    }
};