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
    
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      unordered_map<int,int>child;
        for(int i=0;i<descriptions.size();i++){
            child[descriptions[i][1]]++;
        }
        int parentind;
        int parent;
        for(int i=0;i<descriptions.size();i++){
            if(child.find(descriptions[i][0])==child.end()){
                parentind=i;
                parent=descriptions[i][0];
                break;
            }
        }
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<descriptions.size();i++){
            mp[descriptions[i][0]].push_back({descriptions[i][2],descriptions[i][1]});
        }
        queue<TreeNode*>q;
        TreeNode*root=new TreeNode(parent);
        q.push(root);
        while(!q.empty()){
           int size=q.size();
            
            while(size>0){
                TreeNode*temp=q.front();
                q.pop();
                int ind=temp->val;
                for(auto u:mp[ind]){
                    if(u.first==0){
                        temp->right=new TreeNode(u.second);
                        q.push(temp->right);
                    }
                    else{
                        temp->left=new TreeNode(u.second);
                        q.push(temp->left);
                    }
                }
                size--;
            }
        }
        return root;
        
        
    }
};