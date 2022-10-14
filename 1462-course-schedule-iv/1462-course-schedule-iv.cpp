class Solution {
public:
   void checkpath(vector<int>adj[],int i,vector<bool>&visited){
       visited[i]=true;
        for(auto u:adj[i]){
            if(visited[u]==false)
                checkpath(adj,u,visited);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++){
            int src=queries[i][0];
            int dst=queries[i][1];
            vector<bool>visited(numCourses,false);
           checkpath(adj,src,visited);
            ans.push_back(visited[dst]);
        }
        return ans;
    }
};