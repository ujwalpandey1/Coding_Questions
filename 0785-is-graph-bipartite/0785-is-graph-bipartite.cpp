class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>mp;
        
        int n= graph.size();
        vector<int>color(n,-1);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);
                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    for(auto u:graph[top]){
                        if(color[u]==-1){
                            color[u]=!color[top];
                            q.push(u);
                        }
                        else{
                            if(color[top]==color[u]) return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};