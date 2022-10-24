class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        
       intervals.push_back(newInterval);
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans[ans.size()-1][1]>=intervals[i][0]){
                ans[ans.size()-1][1]=max(intervals[i][1],ans[ans.size()-1][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
       return ans;
    }
};