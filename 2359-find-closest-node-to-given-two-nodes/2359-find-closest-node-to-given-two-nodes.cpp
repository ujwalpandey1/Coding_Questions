class Solution {
public:
    vector<int>distance(unordered_map<int,vector<pair<int,int>>>mp,int src,int n){
        set<pair<int,int>>st;
        st.insert({0,src});
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        while(!st.empty()){
            auto top=*(st.begin());
            st.erase(st.begin());
            int topnode=top.second;
            int topdis=top.first;
            for(auto i:mp[topnode]){
               if(topdis+i.second<dist[i.first]){
                   auto index=st.find({dist[i.first],i.first});
                   if(index!=st.end()){
                       st.erase(index);
                   }
                   dist[i.first]=i.second+topdis;
                   st.insert({dist[i.first],i.first});
               }
            }
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int,vector<pair<int,int>>>mp;
        int n=edges.size();
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
            mp[i].push_back({edges[i],1});
        }
      
        vector<int>v1=distance(mp,node1,n);
        vector<int>v2=distance(mp,node2,n);
        
           int minDist = INT_MAX, node = -1;
        
		
        for(int i=0; i<n; i++) {
            int dist = max(v1[i], v2[i]);
            if(dist < minDist) {
                minDist = dist;
                node = i;
            }
        }
        
        return node;
    }
};