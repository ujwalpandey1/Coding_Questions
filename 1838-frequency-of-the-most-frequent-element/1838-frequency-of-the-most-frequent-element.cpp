class Solution {
public:
    
    
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
       int i=0;
        int j=0;
        int n=nums.size();
       long long  int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            if((long)(j-i+1)*(long)nums[j]-sum<=k){
                ans=max(ans,j-i+1);
               
            }
            else if((long)(j-i+1)*(long)nums[j]-sum>k){
                while((long)(j-i+1)*(long)nums[j]-sum>k){
                    sum-=nums[i];
                  
                    i++;
                     
                }
            }
            j++;
        }
        return ans;
    }
};