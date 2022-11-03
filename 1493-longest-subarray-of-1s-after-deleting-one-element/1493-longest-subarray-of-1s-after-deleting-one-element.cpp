class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
          
            if(mp[0]<=1){
               int res=j-i;
                ans=max(ans,res);

            }
            else if(mp[0]>1){
                while(mp[0]>1){
                    mp[nums[i]]--;
                    i++;
                }
               
            }
            j++;
           
            
        }
        return ans;
    }
};