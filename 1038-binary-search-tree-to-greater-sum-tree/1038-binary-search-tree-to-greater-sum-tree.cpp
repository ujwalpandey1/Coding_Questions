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
    unordered_map<int,vector<int>>mp;
    void make(TreeNode*root){
        if(root==NULL) return;
        if(root->left){
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
            
        }
        if(root->right){
          mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        make(root->left);
        make(root->right);
    }
    void find(int &sum,int i,int val,vector<bool>&vis){
        vis[i]=true;
        if(i>=val) sum+=i;
        for(auto u:mp[i]){
           
                if(vis[u]==false)
                find(sum,u,val,vis);
            
        }
    }
   void build(TreeNode*root){
        if(root==NULL) return;
        int sum=0;
        vector<bool>vis(101,false);
        find(sum,root->val,root->val,vis);
        root->val=sum;
       build(root->left);
       build(root->right);
       
    }
    TreeNode* bstToGst(TreeNode* root) {
        TreeNode*curr=root;
        make(curr);
        TreeNode*p=root;
        build(p);
        int s=0;
        
        return root;
    }
};