class Solution {
public:
 
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>start;
        vector<int>end;
       map<int,int>mp;
        for(int i=0;i<intervals.size();i++){
           
            mp[intervals[i][0]]=i;
        }
        vector<int>ans(intervals.size(),-1);
        for(int i=0;i<intervals.size();i++){
           
                auto t=mp.lower_bound(intervals[i][1]);
              if(t!=mp.end()) ans[i]=t->second;
            
            
        }
        return ans;
    }
};