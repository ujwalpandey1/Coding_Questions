class Solution {
public:
    void solve(int i,set<vector<int>>&st,vector<int>nums){
        if(i>=nums.size()){
            st.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
   
            swap(nums[i],nums[j]);
            solve(i+1,st,nums);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
       
        solve(0,st,nums);
         while(!st.empty()){
            ans.push_back(*(st.begin()));
            st.erase(st.begin());
        }
        return ans;
    }
};