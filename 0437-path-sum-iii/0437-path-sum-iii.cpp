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
    void solve(TreeNode*root,int targetSum,int&ans){
        if(root==NULL) return;
        if(1LL*root->val-1LL*targetSum==0){
            ans++;
           
        }
        solve(root->left,1LL*targetSum-1LL*root->val,ans);
      solve(root->right,1LL*targetSum-1LL*root->val,ans);
      
    }
    void solve2(TreeNode*root,int targetSum,int &res){
        if(root==NULL) return;
        int ans=0;
        solve(root,targetSum,ans);
        res+=ans;
        solve2(root->left,targetSum,res);
        solve2(root->right,targetSum,res);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        int res=0;
        if(root->val==1000000000) return 0;
        solve2(root,targetSum,res);
        return res;
    }
};