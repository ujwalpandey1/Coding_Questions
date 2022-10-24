class Solution {
public:
    void solve(int i,vector<int>&temp,vector<vector<int>>&ans,vector<int>nums){
        
        
            ans.push_back(temp);
           
        
        for(int j=i;j<nums.size();j++){
        temp.push_back(nums[j]);
        solve(j+1,temp,ans,nums);
        temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int>temp;
        vector<vector<int>>ans;
        int i=0;
       solve(i,temp,ans,nums);
        return ans;
    }
};