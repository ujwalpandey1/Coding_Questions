class Solution {
public:
    
    
    int jump(vector<int>& nums) {
        int n=nums.size();
       int jump=0;
        int currend=0;
        int maxreach=0;
        for(int i=0;i<n-1;i++){
            maxreach=max(nums[i]+i,maxreach);
            if(currend==i){
                
                jump++;
                currend=maxreach;
            }
        }
       return jump;
    }
};