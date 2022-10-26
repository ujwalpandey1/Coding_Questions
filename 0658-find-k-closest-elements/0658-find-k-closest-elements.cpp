class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
     int diff=INT_MAX;
        int index;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]-x)<diff){
                index=i;
                diff=abs(nums[i]-x);
            }
        }
       int left=index;
       int right=index;
       while(right-left+1!=k){
           if(left>0&&right<nums.size()-1&&abs(nums[right+1]-x)>=abs(nums[left-1]-x)) left--;
           else if(right<nums.size()-1&&left>0&&abs(nums[left-1]-x)>abs(nums[right+1]-x)) right++;
           else if(left==0&&right-left+1!=k&&right<nums.size()) right++;
           else if(right==nums.size()-1&&right-left+1!=k&&left>0) left--;
       }
        vector<int>ans;
        for(int i=left;i<=right;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};