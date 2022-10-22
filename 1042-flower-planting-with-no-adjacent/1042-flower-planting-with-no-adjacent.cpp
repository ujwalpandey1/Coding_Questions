class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<paths.size();i++){
            mp[paths[i][0]].push_back(paths[i][1]);
            mp[paths[i][1]].push_back(paths[i][0]);
        }
        vector<int>color(n+1,-1);
        queue<int>q;
        
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=1;
                q.push(i);
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    for(auto u:mp[top]){
                        if(color[u]==-1){
                          if(color[top]<4)  color[u]=color[top]+1;
                            else color[u]=1;
                            q.push(u);
                        }
                       else if(color[u]==color[top]){
                           if(color[top]<4) color[u]=color[top]+1;
                           else color[u]=1;
                       }
                        
                    }
                }
            }
        }
        color.erase(color.begin());
        return color;
    }
};