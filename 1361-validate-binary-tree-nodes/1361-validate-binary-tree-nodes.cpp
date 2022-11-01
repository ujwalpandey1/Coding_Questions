class Solution {
public:
  void dfs(int parent,vector<int>mp[],vector<bool>&visited){
      visited[parent]=true;
      for(auto x:mp[parent]){
          if(visited[x]==false) dfs(x,mp,visited);
      }
  }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indegree(n,0);
       vector<int>mp[n];
        for(int i=0;i<n;i++){
           if(leftChild[i]!=-1){ mp[i].push_back(leftChild[i]); indegree[leftChild[i]]++;}
           if(rightChild[i]!=-1){ mp[i].push_back(rightChild[i]); indegree[rightChild[i]]++;}
        }
        int parent=-1;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
               if(parent==-1) parent=i;
                else return false;
            }
            
        }
       if(parent==-1) return false;
        for(int i=0;i<n;i++)
        {
           if(i!=parent&&indegree[i]>1){
               return false;
           }
        }       
       vector<bool>visited(n,false);
        dfs(parent,mp,visited);
        for(auto u:visited){
            if(u==false) return false;
        }
       return true;
    }
};