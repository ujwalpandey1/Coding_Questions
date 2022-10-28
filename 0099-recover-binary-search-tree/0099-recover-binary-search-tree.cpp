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
    TreeNode*ans1=NULL;
     TreeNode*ans2=NULL;
    vector<int>inor;
    void inorder(TreeNode*root){
        if(root==NULL) return ;
        inorder(root->left);
        inor.push_back(root->val);
        inorder(root->right);
    }
    void findNode(TreeNode*root,int find1,int find2){
        if(root==NULL) return;
        if(root->val==find1){
            ans1=root;
            
        }
        if(root->val==find2){
            ans2=root;
        }
        findNode(root->left,find1,find2);
        findNode(root->right,find1,find2);
    }
    void recoverTree(TreeNode*root){
    if(root==NULL) return ;
        inorder(root);
       
       vector<int>nums;
        int v1,v2,index;
        for(auto i:inor) nums.push_back(i);
        sort(nums.begin(),nums.end());
        for(int i=0;i<inor.size();i++){
            if(nums[i]!=inor[i]){
                v1=inor[i];
                index=i;
                break;
            }
        }
        for(int i=index+1;i<inor.size();i++){
            if(nums[i]!=inor[i]){
                v2=inor[i];
                break;
            }
        }
        findNode(root,v1,v2);
        swap(ans1->val,ans2->val);
    }
};