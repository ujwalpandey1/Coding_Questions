class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        
        
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0;i<nums.size()-1;i++){
            for(int  j=i+1;j<nums.size();j++){
                pq.push({(double)nums[i]/(double)nums[j],{nums[i],nums[j]}});
            }
        }
        int n=nums.size();
       int ind=pq.size()-k;
        
      while(ind--){
          pq.pop();
      }
        vector<int>ans;
       ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        
    return ans;
    }
};