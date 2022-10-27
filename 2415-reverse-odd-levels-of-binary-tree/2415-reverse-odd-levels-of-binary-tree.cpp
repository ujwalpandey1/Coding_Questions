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
    TreeNode* reverseOddLevels(TreeNode* root) {
        bool fg=false;
       queue<TreeNode*>qq;
        qq.push(root);
      vector<string>t;
        while(1){
            int size=qq.size();
            if(size==0) break;
            vector<string>ans;
            while(size>0){
                TreeNode*temp=qq.front();
                qq.pop();
               if(temp!=NULL){
                   ans.push_back(to_string(temp->val));
                   if(temp->left) qq.push(temp->left);
                else qq.push(NULL);
             if(temp->right)  qq.push(temp->right);
                else qq.push(NULL);
               }
                else {
                    ans.push_back("#");
                }
              
                size--;
            }
            if(fg==true) reverse(ans.begin(),ans.end());
            fg=!fg;
            for(auto i:ans){
                t.push_back(i);
            }
        }
            queue<TreeNode*>q;
        int i=0;
        TreeNode*node =new TreeNode(stoi(t[i]));
        i++;
        q.push(node);
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            
              if(t[i]!="#"){
                top->left=new TreeNode(stoi(t[i]));
                q.push(top->left);
                i++;
            }
            else{
                top->left=NULL;
                i++;
            }
           
            if(t[i]!="#"){
                top->right=new TreeNode(stoi(t[i]));
                q.push(top->right);
                i++;
            }
            else {
                top->right==NULL;
                i++;
            }
        }
        return node;
    }
};