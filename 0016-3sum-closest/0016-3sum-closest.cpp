class Solution {
public:
    // 3 Sum Leetcode question type
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++){
           int l=i+1;
            int r=nums.size()-1;
            while(l<r){

            if(nums[i]+nums[l]+nums[r]==target){
                return target;
                l++;
                r--;
                
            }
                else if(nums[i]+nums[l]+nums[r]<target){
                    ans.push_back(nums[i]+nums[l]+nums[r]);
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r]>target){
                    ans.push_back(nums[i]+nums[l]+nums[r]);
                    r--;
                }
            }
                
        }
        
        if(ans.size()==1) return ans[0];
       
        int end=ans.size()-1;
        sort(ans.begin(),ans.end());
        int res=INT_MAX;
        for(int i=0;i<ans.size();i++){
            if(ans[i]<target) continue;
            else if(ans[i]==target) return target;
            else if(i>=1&&ans[i]>target){
                int x=min(abs(target-ans[i-1]),abs(target+ans[i+1]));
                int y=min(abs(target-ans[i]),abs(target+ans[i]));
                if(x<y) res=ans[i-1];
                else if(x>y) res=ans[i];
                break;
            }
        }
            if(res==INT_MAX) return ans[end];
            else return res;
        
    }
};