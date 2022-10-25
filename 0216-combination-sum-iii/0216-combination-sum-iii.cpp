class Solution {
public:
    int sum(vector<int>v){
        int s=0;
        for(auto i:v){
            s+=i;;
        }
        return s;
    }
    void solve(int i,vector<int>nums,vector<vector<int>>&ans,vector<int>&temp,int n,int k){

    if(sum(temp)==n&&temp.size()==k){
        ans.push_back(temp);
        return;
    }
        if(i>=nums.size()||sum(temp)>n) return;
        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            solve(j+1,nums,ans,temp,n,k);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<int>temp;
        vector<vector<int>>ans;
        solve(0,nums,ans,temp,n,k);
        return ans;
    }
};