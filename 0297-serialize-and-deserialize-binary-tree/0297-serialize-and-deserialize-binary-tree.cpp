/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        queue<TreeNode*>q;
        q.push(root);
       string res="";
        while(1){
            int size=q.size();
            if(size==0) break;
            string ans="";
            while(size>0){
                TreeNode*temp=q.front();
                q.pop();
               if(temp!=NULL){
                   ans=ans+to_string(temp->val)+' ';
                   if(temp->left) q.push(temp->left);
                else q.push(NULL);
             if(temp->right)  q.push(temp->right);
                else q.push(NULL);
               }
                else {
                    ans=ans+'#'+' ';
                }
              
                size--;
            }
            res+=ans;
        }
        cout<<res;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        vector<string>t;
        stringstream ss(data);
        string temp;
       while(ss>>temp){
            t.push_back(temp);
       }
        queue<TreeNode*>q;
        int i=0;
        TreeNode*root =new TreeNode(stoi(t[i]));
        i++;
        q.push(root);
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
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));