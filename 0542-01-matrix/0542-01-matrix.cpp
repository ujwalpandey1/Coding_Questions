class Solution {
public:
    bool isValid(int i,int j,int n,int m){
        return (i>=0&&j>=0&&i<n&&j<m);
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
       
     vector<vector<int>>ans(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                   
                    q.push({i,j});
                     ans[i][j]=0;
                    
                }
            }
        }
      
        while(!q.empty()){
           
           auto top=q.front();            
                q.pop();
                int x=top.first;
                int y=top.second;
                if(isValid(x+1,y,n,m)&&ans[x+1][y]==-1){
                   
                    q.push({x+1,y});
                     ans[x+1][y]=ans[x][y]+1;
                  
                }
                if(isValid(x-1,y,n,m)&&ans[x-1][y]==-1){
                   
                    q.push({x-1,y});
                     ans[x-1][y]=ans[x][y]+1;
                 
                }
                if(isValid(x,y+1,n,m)&&ans[x][y+1]==-1){
                   
                    q.push({x,y+1});
                     ans[x][y+1]=ans[x][y]+1;
                
                }
                if(isValid(x,y-1,n,m)&&ans[x][y-1]==-1){
                    
                    q.push({x,y-1});
                    ans[x][y-1]=ans[x][y]+1;                    
                }
              
            }
        
         return ans;
    }
};