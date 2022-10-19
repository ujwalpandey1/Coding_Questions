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
    
    unordered_map<int,int>mp;
    int solve(TreeNode*root){
        if(root==NULL) return 0;
        return solve(root->left)+solve(root->right)+root->val;
    }
    void solve2(TreeNode*root){
        if(root==NULL) return;
        int sum=solve(root);
        mp[sum]++;
        solve2(root->left);
        solve2(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        solve2(root);
        int maxi=INT_MIN;
        for(auto i:mp){
            maxi=max(maxi,i.second);    
        }
        for(auto i:mp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};