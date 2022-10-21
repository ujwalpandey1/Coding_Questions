class Solution {
public:
    bool isValid(int i,int j,int n,int m,vector<vector<char>>&board){
        return (i>=0&&j>=0&&i<n&&j<m&&board[i][j]=='O');
    }
    
    void DFS(int i,int j,int n,int m,vector<vector<char>>&board){
        board[i][j]='P';
        if(isValid(i+1,j,n,m,board)){
            DFS(i+1,j,n,m,board);
        }
        if(isValid(i-1,j,n,m,board)){
            DFS(i-1,j,n,m,board);
        }
        if(isValid(i,j+1,n,m,board)){
            DFS(i,j+1,n,m,board);
        }
        if(isValid(i,j-1,n,m,board)){
            DFS(i,j-1,n,m,board);
        }
    }
     void DFS2(int i,int j,int n,int m,vector<vector<char>>&board){
        board[i][j]='X';
        if(isValid(i+1,j,n,m,board)){
            DFS2(i+1,j,n,m,board);
        }
        if(isValid(i-1,j,n,m,board)){
            DFS2(i-1,j,n,m,board);
        }
        if(isValid(i,j+1,n,m,board)){
            DFS2(i,j+1,n,m,board);
        }
        if(isValid(i,j-1,n,m,board)){
            DFS2(i,j-1,n,m,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
           if(board[i][0]=='O') DFS(i,0,n,m,board);
           if(board[i][m-1]=='O') DFS(i,m-1,n,m,board);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') DFS(0,j,n,m,board);
            if(board[n-1][j]=='O') DFS(n-1,j,n,m,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    DFS2(i,j,n,m,board);
                }
            }
        }
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='P') board[i][j]='O';
            }
        }
    }
    
};