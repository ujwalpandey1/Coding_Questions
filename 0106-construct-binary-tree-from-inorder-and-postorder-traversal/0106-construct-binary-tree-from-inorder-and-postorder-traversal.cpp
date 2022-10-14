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
    int position(vector<int>&inorder,int ele){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele){ return i; break;}
        }
        return -1;
    }
    TreeNode*solve(vector<int>postorder,vector<int>&inorder,int s,int e, int &i){
        if(i<0||s>e) return NULL;
        
        TreeNode*root=new TreeNode(postorder[i]);
        int index=position(inorder,postorder[i]);
        i--;
         root->right=solve(postorder,inorder,index+1,e,i);
        root->left=solve(postorder,inorder,s,index-1,i);
       
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=postorder.size()-1;
        return solve(postorder,inorder,0,inorder.size()-1,i);
    }
};