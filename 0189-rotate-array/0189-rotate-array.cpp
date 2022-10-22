class Solution {
public:
    void help(int s,int e,vector<int>&nums){
        while(s<=e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }
    }
    void rotate(vector<int>& nums, int k) {
      k=k%nums.size();
       reverse(nums.begin(),nums.end());
        help(0,k-1,nums);
        reverse(nums.begin()+k,nums.end());
    }
};