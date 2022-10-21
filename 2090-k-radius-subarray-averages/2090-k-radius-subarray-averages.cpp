class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
       int i=0;
        int j=0;
        int n=nums.size();
        long long int sum=0;
        vector<int>res(n,-1);
        vector<int>ans;
        while(j<n){
            sum+=nums[j];
            if(j-i+1<2*k+1) j++;
            else if(j-i+1==2*k+1){
                 int t=(sum/(2*k+1));
                ans.push_back(t);
                sum-=nums[i];
                i++;
                j++;
            }
        }
       if(ans.size()==0) return res;
        int size=ans.size();
         
     for(int i=k;i<k+size;i++){
            res[i]=ans[i-k];
        }
        return res;
    }
};