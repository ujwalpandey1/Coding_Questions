class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        if(n==0) return ans;
        if(n==1){
            ans.push_back(0);
            return ans;
        }
        vector<int>degree(n,0);
         unordered_map<int,vector<int>>mp;
        for(int i=0;i<edges.size();i++){    
            int u=edges[i][0];
            int v=edges[i][1];
           
            mp[u].push_back(v);
            mp[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
                degree[i]--;
            }
        }
        while(!q.empty()){
            ans.clear();
            int size=q.size();
            while(size>0){
                int top=q.front();
                q.pop();
                ans.push_back(top);
                for(auto u:mp[top]){

                degree[u]--;
                    if(degree[u]==1) q.push(u);
                }
                size--;
            }
        }
     return ans; 
    }
};