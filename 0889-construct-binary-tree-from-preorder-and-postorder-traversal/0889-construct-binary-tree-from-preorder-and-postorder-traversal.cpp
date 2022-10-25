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
    int find(vector<int>postorder,int ele){
        for(int i=0;i<postorder.size();i++){
            if(postorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode*build(vector<int>&preorder,vector<int>&postorder,int preStart,int preEnd,int posStart,int posEnd){
        if(preStart>preEnd) return NULL;
        TreeNode*root=new TreeNode(preorder[preStart]);
        if(preStart==preEnd) return root;
        int pos=find(postorder,preorder[preStart+1]);
        int len=pos-posStart+1;
        root->left=build(preorder,postorder,preStart+1,preStart+len,posStart,pos);
        root->right=build(preorder,postorder,preStart+len+1,preEnd,pos+1,posEnd-1);
        return root;
        
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
       
        return build(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);
    }
};