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
    void make(unordered_map<int,vector<int>>&mp,TreeNode*root){
        if(root==NULL) return ;
        if(root->left==NULL&&root->right==NULL) return;
      if(root->left)  mp[root->val].push_back(root->left->val);
      if(root->left)  mp[root->left->val].push_back(root->val);
      if(root->right)  mp[root->val].push_back(root->right->val);
      if(root->right)  mp[root->right->val].push_back(root->val);
        make(mp,root->left);
        make(mp,root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==NULL) return ans;
        unordered_map<int,vector<int>>mp;
        TreeNode*curr=root;
        make(mp,curr);
        int src=target->val;
        
        queue<int>q;
        int l=0;
        q.push(src);
        vector<bool>vis(501,false);
        vis[src]=true;
        while(!q.empty()){
         int size=q.size();
           
        
           vector<int>data;
            while(size>0){
                int top=q.front();
                q.pop();
                if(l==k) ans.push_back(top);
                for(auto u:mp[top]){
                  if(vis[u]==false){
                      vis[u]=true;
                      q.push(u);
                      
                  }
                }
                size--;
            }
            l++;
            
            
        }
        return ans;
    }
};