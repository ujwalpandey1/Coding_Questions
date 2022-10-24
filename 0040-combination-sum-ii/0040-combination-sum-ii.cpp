class Solution {
public:
    int sum(vector<int>v){
        int s=0;
        for(auto i:v){
            s+=i;
            
        }
        return s;
    }
    void solve(int i,vector<int>&temp,vector<vector<int>>&ans,vector<int>candidates,int target){
        if(sum(temp)==target){
            ans.push_back(temp);
        }
        if(sum(temp)>target||i>candidates.size()) return;
        
        for(int j=i;j<candidates.size();j++){
            if(j!=i&&candidates[j-1]==candidates[j]) continue;
            temp.push_back(candidates[j]);
            solve(j+1,temp,ans,candidates,target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>temp;
        solve(0,temp,ans,candidates,target);
        return ans;
    }
};