class Solution {
public:
    
    bool check(vector<int>&nums,long long mid){
       long long int carry=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>mid){
                carry+=nums[i]-mid;
            }
            else{
                carry-=min(carry,mid-nums[i]);
            }
        }
        return carry<=0;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int ans=0;
        int l=0;
        int r=1e9;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(nums,(long long)mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};