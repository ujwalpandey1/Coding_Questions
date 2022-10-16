class Solution {
public:
    void make(int v,vector<int>&parent,vector<int>&size){
        parent[v]=v;
        size[v]=1;
    }
    int find(int v,vector<int>&parent){
        if(v==parent[v]) return v;
        return  find(parent[v],parent);
    }
    void Union(int a,int b,vector<int>&parent,vector<int>&size){
        a=find(a,parent);
        b=find(b,parent);
        if(a!=b){
            if(size[a]>size[b]){
                parent[b]=a;
                size[a]+=size[b];
            }
            else {
                parent[a]=b;
                size[b]+=size[a];
                }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n=edges.size();
       vector<int>parent(n+1);
        vector<int>size(n+1);
       vector<int>ans;
       
        for(int i=1;i<=n;i++){
            make(i,parent,size);
        }
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(find(u,parent)!=find(v,parent)){
                Union(u,v,parent,size);
            }
            else {
            ans.push_back(u);
            ans.push_back(v);
            }
        }
        return ans;
    }
};