class Solution {
public:
    int search(vector<int>& nums, int target) {
       
    
        int ind = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ind==nums.size())
            return -1;
        return nums[ind]==target ? ind:-1;
    
    }
};