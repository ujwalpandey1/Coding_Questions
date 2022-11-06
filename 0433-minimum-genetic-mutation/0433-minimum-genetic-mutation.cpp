class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string>b(bank.begin(),bank.end());
        if(b.find(end)==b.end()) return -1;
        int ans=0;
        queue<string>q;
        q.push(start);
        unordered_map<string,int>vis;
        vis[start]=1;
        while(!q.empty()){
            int size=q.size();
            int res=0;
            while(size>0){
                string top=q.front();
                q.pop();
                if(top==end) return ans;
               
                for(int i=0;i<8;i++){
                    string temp;
                    temp=top;
                    temp[i]='T';
                    if(b.find(temp)!=b.end()&&vis[temp]==0){
                        q.push(temp);
                        vis[temp]=1;
                        res++;
                    }
                    temp=top;
                    temp[i]='G';
                    if(b.find(temp)!=b.end()&&vis[temp]==0){
                        q.push(temp);
                        vis[temp]=1;
                        res++;
                    }
                    temp=top;
                    temp[i]='C';
                    if(b.find(temp)!=b.end()&&vis[temp]==0){
                        q.push(temp);
                        vis[temp]=1;
                        res++;
                    }
                    temp=top;
                    temp[i]='A';
                    if(b.find(temp)!=b.end()&&vis[temp]==0){
                        q.push(temp);
                        vis[temp]=1;
                        res++;
                    }
                }
                size--;
            }
            if(res!=0) ans++;
        }
        return -1;
    }
};