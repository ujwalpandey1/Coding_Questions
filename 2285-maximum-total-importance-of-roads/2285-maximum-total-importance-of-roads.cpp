class Solution {
public:
     static bool comp(pair<int,int>&a,pair<int,int>&b){
        return (b.second<a.second);
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
      vector<int>degree(n,0);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            degree[u]++;
            degree[v]++;
        }
        int imp=n;
        vector<pair<int,int>>v;
        unordered_map<int,int>importance;
        for(int i=0;i<n;i++){
            v.push_back({i,degree[i]});
        }
        sort(v.begin(),v.end(),comp);
        
        for(auto i:v){
           if(imp>=1) importance[i.first]=imp;
            imp--;
        }
       
        long long total_imp=0;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            total_imp+=importance[u]+importance[v];
        }
        return total_imp;
    }
};