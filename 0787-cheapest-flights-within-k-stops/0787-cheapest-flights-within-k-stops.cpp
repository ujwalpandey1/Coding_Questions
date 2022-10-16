class Solution {
public:
    

  
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
       unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        q.push({0,{0,src}});
        while(!q.empty()){
           auto top=q.front();
            q.pop();
            int stops=top.first;
            int topdis=top.second.first;
            int topnode=top.second.second;
            for(auto i:adj[topnode]){
                if(stops>k) continue;
                else{
                    if(topdis+i.second<dist[i.first]){
                        
                        dist[i.first]=i.second+topdis;
                        q.push({stops+1,{dist[i.first],i.first}});
                    }
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};