class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<indices.size();i++){
            pq.push({indices[i],s[i]});
        }
        while(!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};