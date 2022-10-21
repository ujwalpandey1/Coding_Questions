class Solution {
public:
  
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int x=jug1Capacity;
        int y=jug2Capacity;
        int max=jug2Capacity+jug1Capacity;
       unordered_map<int,int>vis;
       queue<int>q;
        q.push(0);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            if(vis[top]==0){
                vis[top]=1;
                if(top==targetCapacity) return true;
            }
            if(top+x>0&&top+x<=max&&vis[top+x]==0){
                q.push(top+x);
            }
             if(top-x>0&&top-x<=max&&vis[top-x]==0){
                q.push(top-x);
            }
             if(top+y>0&&top+y<=max&&vis[top+y]==0){
                q.push(top+y);
            }
             if(top-y>0&&top-y<=max&&vis[top-y]==0){
                q.push(top-y);
            }
            
            
        }
        if(vis[targetCapacity]==0) return false;
        return true;
    }
};