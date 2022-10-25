class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        vector<int>ans;
        if(nums.size()==0) return ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int key=nums[i];
             int count=1;
            while(i<nums.size()-1&&nums[i+1]==key){
                i++;
                count++;
            }
            
            if(count>n/3) ans.push_back(nums[i]);

        }
        return ans;
    }
};