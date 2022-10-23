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
    TreeNode*solve(TreeNode*root,int target){
        if(root==NULL) return NULL;
        if(root->left==NULL&&root->right==NULL&&root->val==target){
            return NULL;
        }
       else return root;
    }
    void solve2(TreeNode*root,int target){
       if(root==NULL) return;
        solve2(root->left,target);
        solve2(root->right,target);
       if(root->left&&root->left->val==target) {
           root->left=solve(root->left,target);
       }
        if(root->right&&root->right->val==target){
            root->right=solve(root->right,target);
        }
        
        
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL) return NULL;
        TreeNode*curr=root;
        solve2(root,target);
        if(root==NULL) return NULL;
        if(root->left==NULL&&root->right==NULL&&root->val==target) return NULL;
        return curr;
    }
};