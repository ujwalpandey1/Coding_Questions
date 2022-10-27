class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1;
        int i=0;
        int j=0;
        int n=nums.size();
        int cnt=0;
        while(j<n){
            p*=nums[j];
             if(p>=k){
                while(i<nums.size()&&p>=k){
                    p/=nums[i];
                    i++;
                }

            }
            if(p<k) {
                cnt+=j-i+1;
               
            }
          
            j++;
            
        }
        return cnt;
    }
};