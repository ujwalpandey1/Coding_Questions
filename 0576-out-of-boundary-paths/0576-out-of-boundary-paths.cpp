class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][51];
    int DFS(int i,int j,int m,int n,int maxMoves){
       if(i>=m||i<0||j>=n||j<0) return 1;
        if(maxMoves<=0) return 0;
        if(dp[i][j][maxMoves]!=-1) return dp[i][j][maxMoves];
        long res=0;
        res+=DFS(i+1,j,m,n,maxMoves-1)%mod;
        res+=DFS(i-1,j,m,n,maxMoves-1)%mod;
        res+=DFS(i,j+1,m,n,maxMoves-1)%mod;
        res+=DFS(i,j-1,m,n,maxMoves-1)%mod;
        return dp[i][j][maxMoves]=res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return DFS(startRow,startColumn,m,n,maxMove)%mod;
    }
};