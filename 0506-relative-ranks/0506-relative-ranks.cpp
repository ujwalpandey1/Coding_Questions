class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>ans(n);
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
            
        }
        vector<string>medals={"Gold Medal","Silver Medal","Bronze Medal"};
        int j=1;
        int i=0;
        while(pq.size()>0&&j<=3){
            auto top=pq.top();
            pq.pop();
            ans[top.second]=medals[i++];
            j++;
        }
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            ans[top.second]=to_string(j++);
        }
        return ans;
    }
};