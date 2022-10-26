class Solution {
public:
    bool isValid(vector<vector<char>>&board,int i,int j,int n,int m){
        return (i>=0&&j>=0&&i<n&&j<m&&board[i][j]=='X');
    }
    void DFS(vector<vector<char>>&board,int i,int j,int n,int m){
        board[i][j]='.';
        if(isValid(board,i+1,j,n,m)) DFS(board,i+1,j,n,m);
        if(isValid(board,i-1,j,n,m)) DFS(board,i-1,j,n,m);
        if(isValid(board,i,j+1,n,m)) DFS(board,i,j+1,n,m);
        if(isValid(board,i,j-1,n,m)) DFS(board,i,j-1,n,m);
       
    }
    int countBattleships(vector<vector<char>>& board) {
        int ans=0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    ans++;
                    DFS(board,i,j,n,m);
                }
            }
        }
        return ans;
    }
};