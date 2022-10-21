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
    TreeNode*help(TreeNode*root){
       if(root->left==NULL&&root->right==NULL) return NULL;
       else if(root->left!=NULL&&root->right==NULL) return root->left;
       else if(root->left==NULL&&root->right!=NULL) return root->right;
       else{
           TreeNode*pred=root->right;
           TreeNode*curr=root->left;
           while(curr->right) curr=curr->right;
           curr->right=pred;
           return root->left;
           
       } 
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL) return NULL ;
       if(root->left==NULL&&root->right==NULL&&root->val==key) return NULL;
       if(root->left==NULL&&root->right==NULL&&root->val!=key) return root;
    if(root->val==key){
        return help(root);
    }
        TreeNode*dum=root;
        while(root!=NULL){
            if(root->val<key){
                if(root->right!=NULL&&root->right->val==key){
                    root->right=help(root->right);
                    break;
                }
                else root=root->right;
                
            }
            else if(root->val>key){
                if(root->left!=NULL&&root->left->val==key) {
                    root->left=help(root->left);
                   break;}
                else  root=root->left;
            }
           else{
               root=root->right;
           }
        }
        return dum;
      
    }
};