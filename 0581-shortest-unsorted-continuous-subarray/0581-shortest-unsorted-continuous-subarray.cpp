class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
     vector<int>arr;
        if(nums.size()==0||nums.size()==1) return 0;
        for(auto i:nums) arr.push_back(i);
        sort(arr.begin(),arr.end());
        int left=0;
        int right=nums.size()-1;
        while(left<nums.size()&&nums[left]==arr[left]) left++;
        while(right>0&&nums[right]==arr[right]) right--;
        if(left>=right) return 0;
        return right-left+1;
    }
};