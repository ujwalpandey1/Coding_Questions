class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index=-1;
        int start=0;
        int end=nums.size()-1;
      int ans;
        while(start<=end){
            int mid=start+(end-start)/2;
            ans=end;
            if(nums[mid]==target){
                index=mid;
                break;
            }
            else if(nums[mid]<target) start=mid+1;
            else end=mid-1;
            
        }
      if(index!=-1) return index;
     return end+1;
    }
};