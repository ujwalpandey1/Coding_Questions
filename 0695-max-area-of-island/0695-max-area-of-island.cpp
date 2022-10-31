class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&grid){
        return (i>=0&&j>=0&&i<n&&j<m&&grid[i][j]==1);
    }
    void DFS(int i,int j,int n,int m,vector<vector<int>>&grid,int &count){
        grid[i][j]=0;
        count++;
        if(isValid(i+1,j,n,m,grid)) DFS(i+1,j,n,m,grid,count);
        if(isValid(i-1,j,n,m,grid)) DFS(i-1,j,n,m,grid,count);
        if(isValid(i,j+1,n,m,grid)) DFS(i,j+1,n,m,grid,count);
        if(isValid(i,j-1,n,m,grid)) DFS(i,j-1,n,m,grid,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1){
                   
                   int count=0;
                   DFS(i,j,n,m,grid,count);
                   ans=max(ans,count);
               }
            }
        }
        return ans;
    }
};