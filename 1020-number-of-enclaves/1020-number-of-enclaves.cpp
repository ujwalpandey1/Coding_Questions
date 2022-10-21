class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&grid){
        return (i>=0&&j>=0&&i<n&&j<m&&grid[i][j]==1);
    }
    void DFS(int i,int j,int n,int m,vector<vector<int>>&grid){
            grid[i][j]=0;
        
        if(isValid(i+1,j,n,m,grid)) DFS(i+1,j,n,m,grid);
         if(isValid(i-1,j,n,m,grid)) DFS(i-1,j,n,m,grid);
          if(isValid(i,j+1,n,m,grid)) DFS(i,j+1,n,m,grid);
          if(isValid(i,j-1,n,m,grid)) DFS(i,j-1,n,m,grid);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
           if(grid[i][0]==1) DFS(i,0,n,m,grid);
           if(grid[i][m-1]==1) DFS(i,m-1,n,m,grid);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1) DFS(0,j,n,m,grid);
            if(grid[n-1][j]==1) DFS(n-1,j,n,m,grid);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    
                    ans++;
                }
            }
        }
        return ans;
    }
};