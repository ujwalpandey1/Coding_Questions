class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
       unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        unordered_map<int,int>mp2;
       for(int i=0;i<nums.size();i++){
           if(mp[nums[i]]==0) continue;
          mp[nums[i]]--;
           if(mp2[nums[i]-1]!=0){
               mp2[nums[i]-1]--;
               mp2[nums[i]]++;
           }
           else if(mp[nums[i]+1]>0&&mp[nums[i]+2]>0){
               mp[nums[i]+1]--;
               mp[nums[i]+2]--;
               mp2[nums[i]+2]++;
           }
           else {
               return false;
           }
           
       }
        
      
        return true;
    }
};