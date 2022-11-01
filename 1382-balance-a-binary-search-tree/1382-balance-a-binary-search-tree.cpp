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
    vector<int>inorder;
    void solve(TreeNode*root){
        if(root==NULL) return;
        solve(root->left);
        inorder.push_back(root->val);
        solve(root->right);
    }
    TreeNode*build(vector<int>inorder,int s,int e){
        if(s>e) return NULL;
        int mid=(s+e)/2;
        TreeNode*node=new TreeNode(inorder[mid]);
        node->left=build(inorder,s,mid-1);
        node->right=build(inorder,mid+1,e);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        solve(root);
        return build(inorder,0,inorder.size()-1);
    }
};