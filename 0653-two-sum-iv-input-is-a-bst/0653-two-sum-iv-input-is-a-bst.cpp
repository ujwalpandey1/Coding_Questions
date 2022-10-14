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
    
    bool findTarget(TreeNode* root, int k) {
        TreeNode*curr=root;
        vector<int>ans;
        while(curr){
            if(curr->left){
                TreeNode*temp=curr->left;
                TreeNode*pred=curr->left;
                while(pred->right){
                    pred=pred->right;
                }
                pred->right=curr;
                curr->left=NULL;
                curr=temp;
                
            
            }
            else {
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            if(ans[i]+ans[j]<k) i++;
            else if(ans[i]+ans[j]>k) j--;
            else return true;
        }
        return false;
    }
};