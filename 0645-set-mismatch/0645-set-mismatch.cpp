class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>res;
        sort(nums.begin(),nums.end());
       
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]) {
                res.push_back(nums[i]);
                break;
            }
        }
       
      set<int>st;
        for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
        }
        for(int i=1;i<=nums.size();i++){
            if(st.find(i)==st.end()) {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};