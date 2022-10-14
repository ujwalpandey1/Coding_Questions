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
    void creategraph(TreeNode*root){
        if(root==NULL) return ;
        
      if(root->left!=NULL)  mp[root->val].push_back(root->left->val);
     if(root->right!=NULL) mp[root->val].push_back(root->right->val);
        if(root->left!=NULL)  mp[root->left->val].push_back(root->val);
        if(root->right!=NULL)  mp[root->right->val].push_back(root->val);
       creategraph(root->left);
        creategraph(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
      
        creategraph(root);
       
       vector<bool>visited(100001,false);
        queue<int>q;
        int res=0;
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int size=q.size();
            int tempres=0;
            while(size>0){
                int top=q.front();
                q.pop();
                for(auto u:mp[top]){
                    if(visited[u]==false){
                        visited[u]=true;
                        
                        tempres++;
                        q.push(u);
                    }
                }
                size--;
            }
            if(tempres!=0) res++;
        }
        return res;
    }
};