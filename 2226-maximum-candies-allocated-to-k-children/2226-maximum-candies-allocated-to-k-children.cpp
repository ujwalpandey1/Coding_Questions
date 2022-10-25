class Solution {
public:
    bool isValid(vector<int>nums,int mid,long long k){
        long long count=0;
       
        for(int i=0;i<nums.size();i++){
        count+=nums[i]/mid;
        }
     
        return (count>=k);
    }
    int maximumCandies(vector<int>& nums, long long k) {
        
        int n=nums.size();
       long long int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        if(sum<k) return 0;
        int max_ele=*max_element(nums.begin(),nums.end());
        
        int start=1;
        int end=max_ele;
        int res;
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(nums,mid,k)){
                res=mid;
                start=mid+1;
            
            }
            else end=mid-1;
        }
 
        return res;
    }
};