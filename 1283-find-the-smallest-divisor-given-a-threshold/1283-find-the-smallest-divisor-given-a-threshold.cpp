class Solution {
public:
    bool check(vector<int>&nums,int threshold,int mid){
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)mid);
        }
        return sum<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start=1;
        int ans=0;
        int end=1e6;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(nums,threshold,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};