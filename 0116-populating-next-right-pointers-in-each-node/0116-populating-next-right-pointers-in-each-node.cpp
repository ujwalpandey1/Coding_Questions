/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   
    
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
       
      queue<Node*>q;
        q.push(root);
        while(1){
            int size=q.size();
            vector<Node*>data;
            if(size==0){
                break;
            }
            while(size>0){
                
                Node*temp=q.front();
                q.pop();
                data.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                size--;
            }
           if(data.size()>1){
               
               for(int j=0;j<data.size()-1;j++){
                   data[j]->next=data[j+1];
               }
               data[data.size()-1]->next=NULL;
           }
            else if(data.size()==1){
                data[0]->next==NULL;
            }
        }
       
        return root;
    }
};