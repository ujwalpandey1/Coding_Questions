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
    int ans=0;
    int helper(TreeNode*root,int par){
    if(root==NULL) return 0;
    int l=helper(root->left,root->val);
    int r=helper(root->right,root->val);
    ans=max(ans,l+r);
        if(par==root->val) return 1+max(l,r);
    
        return 0;
        
    }
   
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL)) return 0;
      
        helper(root,-1);
        return ans;
    }
};