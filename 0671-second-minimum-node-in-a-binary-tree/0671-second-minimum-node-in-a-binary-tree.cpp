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
    void inorder(TreeNode*root,vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL) return -1;
        vector<int>ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        if(ans[0]==ans[ans.size()-1]) return -1;
        int key=ans[0];
        int i=0;
        while(key==ans[i]){
            i++;
        }
        return ans[i];
    }
};