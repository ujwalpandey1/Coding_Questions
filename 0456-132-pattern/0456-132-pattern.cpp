class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;
        int k=-1e9+1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<k) return true;
            
            while(!st.empty()&&nums[i]>st.top()){
                k=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
       
        
        return false;
    }
};