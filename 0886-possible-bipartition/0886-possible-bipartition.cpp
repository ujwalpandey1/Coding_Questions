class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<dislikes.size();i++){
            int u=dislikes[i][0];
            int v=dislikes[i][1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        queue<int>q;
        
        vector<int>color(n+1,-1);
       
       for(int i=1;i<=n;i++){
           if(color[i]==-1){
               color[i]=0;
               q.push(i);
           
        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto u:mp[top]){
                if(color[u]==-1){
                    if(color[top]==0) color[u]=1;
                    else color[u]=0;
                    q.push(u);
                }
                else{
                    if(color[top]==color[u]) return false;
                }
                
            }
           
        }}}
        
        return true;
    }
};