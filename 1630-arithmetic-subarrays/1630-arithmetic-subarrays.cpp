class Solution {
public:
  
    bool solve(vector<int>nums,int l,int r){
       
        vector<long long>arr;
        
        for(int i=l;i<=r;i++){
            arr.push_back(nums[i]);
        }
        
        if(arr.size()<2) return false;
        
        sort(arr.begin(),arr.end());
        int size=arr.size();
        int d=arr[1]-arr[0];
        int a=arr[0];
        for(int i=2;i<size;i++){
            int diff=arr[i]-arr[i-1];
            if(diff==d) continue;
            else return false;
        }
      
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& ls, vector<int>& rs) {
        int N=nums.size();
       
       
        
        vector<bool>ans(ls.size());
        for(int i=0;i<ls.size();i++){
            int l=ls[i];
            int r=rs[i];
            
            ans[i]=(solve(nums,l,r));
        }
        return ans;
        
    }
};