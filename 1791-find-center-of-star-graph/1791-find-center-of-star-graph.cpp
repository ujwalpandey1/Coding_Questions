class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
    unordered_map<int,int>degree;
       for(int i=0;i<edges.size();i++){
           degree[edges[i][0]]++; 
           degree[edges[i][1]]++;
       }
            int max_degree=0;
        for(auto i:degree){
            max_degree=max(max_degree,i.second);
        }
        for(auto i:degree){
            if(i.second==max_degree) return i.first;
        }
        return 0;
    }
};