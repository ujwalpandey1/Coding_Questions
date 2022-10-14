/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  TreeNode*ans=NULL;
    void dfs(TreeNode*o,TreeNode*c,TreeNode*target){
        if(!o) return ;
        if(o==target){
            ans=c;
        
        }
        dfs(o->left,c->left,target);
        dfs(o->right,c->right,target);
    
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode*o=original;
        TreeNode*c=cloned;
      dfs(o,c,target);
        return ans;
        
    }
};