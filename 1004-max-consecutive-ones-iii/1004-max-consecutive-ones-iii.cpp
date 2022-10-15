class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=INT_MIN;
        int i=0;
        int j=0;
        int n=nums.size();
        while(j<n){
            mp[nums[j]]++;
           if(mp[0]<=k){
                ans=max(ans,j-i+1);
            }
            else if(mp[0]>k){
                while(mp[0]>k){
                    mp[nums[i]]--;
                    i++;
                    
                }
            }
            j++;
        }
        return ans==INT_MIN?0:ans;
    }
};