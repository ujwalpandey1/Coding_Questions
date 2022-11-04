class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>>st;
        vector<int>ans;
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(st.size()>0&&st.top().second>arr[i]){
                ans.push_back(st.top().first);
            }
            else{
                while(st.size()>0&&st.top().second<=arr[i]){
                    st.pop();
                }
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top().first);
            }
            st.push({i,arr[i]});
            
        }
        reverse(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++){
            if(ans[i]==-1) ans[i]=0;
            else{
                ans[i]=ans[i]-i;
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]<0) ans[i]=0;
        }
        return ans;
    }
};