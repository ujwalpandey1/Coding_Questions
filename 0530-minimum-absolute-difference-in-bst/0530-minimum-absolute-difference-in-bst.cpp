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
    
    int getMinimumDifference(TreeNode* root) {
     TreeNode*curr=root;
        int ans=INT_MAX;
        vector<int>inorder;
        while(curr){
            if(curr->left){
                TreeNode*pred=curr->left;
                TreeNode*temp=curr->left;
                while(pred->right) pred=pred->right;
                pred->right=curr;
                curr->left=NULL;
                curr=temp;
            }
            else{
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
        for(int i=1;i<inorder.size();i++){
            ans=min(ans,abs(inorder[i]-inorder[i-1]));
        }
        return ans;
    }
};