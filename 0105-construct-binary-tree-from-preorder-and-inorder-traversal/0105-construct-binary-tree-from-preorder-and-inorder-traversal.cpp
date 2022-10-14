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
    int position(vector<int>&inorder,int element){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }
    TreeNode*solve(vector<int>&preorder,vector<int>&inorder,int s,int e,int &i){
        if(i>=preorder.size()||s>e) return NULL;
         TreeNode*node=new TreeNode(preorder[i]);
        
       int index=position(inorder,preorder[i]);
        i++;
        node->left=solve(preorder,inorder,s,index-1,i);
        node->right=solve(preorder,inorder,index+1,e,i);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        return solve(preorder,inorder,0,inorder.size()-1,i);
    }
};