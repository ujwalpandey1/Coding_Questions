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
    bool checkNode(TreeNode*root){
        if(root==NULL) return true;
         if(root->val!=0) return false;
    return checkNode(root->left)&&checkNode(root->right);
    }
    void solve(TreeNode*root){
        if(root==NULL) return;
        if(checkNode(root->left)){
            root->left=NULL;
        
        }
        if(checkNode(root->right)){
            root->right=NULL;
        }
        solve(root->left);
        solve(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
       if(root==NULL) return root;
        TreeNode*curr=root;
        solve(curr);
        if(root==NULL) return NULL;
        if(root->left==NULL&&root->right==NULL&&root->val==0) return NULL;
        return root;
    }
};