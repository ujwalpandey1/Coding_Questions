class Solution {
public:
    double dp[26][26][101];
    double DFS(int i,int j,int n,int k){
        
         if(i<0||j<0||i>=n||j>=n)
            return 0;
         if(k==0) return 1;
        if(dp[i][j][k]) return dp[i][j][k];
       double t= DFS(i+2,j-1,n,k-1)+
        DFS(i+2,j+1,n,k-1)+
        DFS(i-2,j-1,n,k-1)+
        DFS(i-2,j+1,n,k-1)+
        DFS(i-1,j-2,n,k-1)+
        DFS(i-1,j+2,n,k-1)+
        DFS(i+1,j-2,n,k-1)+
        DFS(i+1,j+2,n,k-1);
        
        double res=double(t)/8;
        return dp[i][j][k]=res;
    }
    double knightProbability(int n, int k, int row, int column) {
   
       return  DFS(row,column,n,k);
     
       
    }
};