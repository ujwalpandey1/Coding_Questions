class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            int l=i+1;
            int rem=0-(nums[i]);
            int r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==rem){
                    st.insert({nums[i],nums[l],nums[r]}); l++;r--;}
                 else if(nums[l]+nums[r]<rem) l++;
                    
                    else r--;
                
            }
        }
       for(auto i:st){
           ans.push_back(i);
       }
        return ans;
    }
};