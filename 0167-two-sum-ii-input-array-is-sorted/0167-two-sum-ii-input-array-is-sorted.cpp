class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;;
        int r=nums.size()-1;
        vector<int>ans(2);
        while(l<r){
            if(nums[l]+nums[r]<target) l++;
            else if(nums[l]+nums[r]>target) r--;
            else {
                ans[0]=l+1;
                ans[1]=r+1;
                break;
            }
        }
        return ans;
    }
};