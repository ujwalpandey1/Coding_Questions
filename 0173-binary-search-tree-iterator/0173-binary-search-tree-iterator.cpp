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
class BSTIterator {
public:
  vector<int>ans;
    int i=0;
    BSTIterator(TreeNode* root) {
        
       TreeNode*curr=root;
       while(curr){

       if(curr->left){
           TreeNode*pred=curr->left;
           TreeNode*temp=curr->left;
           while(pred->right) pred=pred->right;
           pred->right=curr;
           curr->left=NULL;
           curr=temp;
       }
           else {
               ans.push_back(curr->val);
               curr=curr->right;
           }
       }
    }
    
    int next() {
        if(i<ans.size()) {

        int x=ans[i];
            i++;
            return x;
        }
        return -1;
    }
    
    bool hasNext() {
       if(i>=ans.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */