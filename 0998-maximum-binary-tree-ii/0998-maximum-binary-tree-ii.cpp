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
 
    TreeNode*node=NULL;
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root==NULL) {
        TreeNode*newnode=new TreeNode(val);
            return newnode;
        }
        if(root->val<val){
            node=new TreeNode(val);
            node->left=root;
            return node;
            
        }
        else if(root->val>val) root->right=insertIntoMaxTree(root->right,val);
        return root;
    }
};