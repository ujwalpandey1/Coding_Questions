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
   
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*>q;
        q.push(root);
        vector<int>parent(101);
        parent[root->val]=-1;
        
        while(1){
            
            int size=q.size();
            set<int>st;
            if(size==0) break;
            
            while(size>0){
                auto top=q.front();
                q.pop();
                st.insert(top->val);
                if(top->left) {q.push(top->left); parent[top->left->val]=top->val;}
                if(top->right) {q.push(top->right); parent[top->right->val]=top->val;}
                size--;
            }
          if(st.find(x)!=st.end()&&st.find(y)!=st.end()&&parent[x]!=parent[y]) return true;
        }
        return false;
    }
};