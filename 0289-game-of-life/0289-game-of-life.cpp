class Solution {
public:
    bool isvalid(int i ,int j,int n,int m,vector<vector<int>>board){
        return(i>=0&&j>=0&&i<n&&j<m&&board[i][j]==1);
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cell=board[i][j];
                int cnt=0;
                if(isvalid(i+1,j,n,m,board)) cnt++;
               
                if(isvalid(i-1,j,n,m,board)) cnt++;
                
                if(isvalid(i,j+1,n,m,board)) cnt++;
                
                if(isvalid(i,j-1,n,m,board)) cnt++;
                
                if(isvalid(i+1,j+1,n,m,board)) cnt++;
                
                if(isvalid(i-1,j-1,n,m,board)) cnt++;
                
                if(isvalid(i+1,j-1,n,m,board)) cnt++;
                
                if(isvalid(i-1,j+1,n,m,board)) cnt++;
                
                if(cell==1){
                    if(cnt<2) ans[i][j]=0;
                    else if(cnt>=2&&cnt<=3) ans[i][j]=1;
                    else if(cnt>3) ans[i][j]=0;
                }
                else{
                    if(cnt==3) ans[i][j]=1;
                    else ans[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};