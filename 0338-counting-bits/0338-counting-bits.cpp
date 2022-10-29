class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(100001);
        ans[0]=0;
        ans[1]=1;
        
        for(int i=2;i<=n;i++){
            ans[i]=ans[i/2]+ans[i%2];
        }
        vector<int>res(n+1);
        for(int i=0;i<=n;i++){
            res[i]=ans[i];
        }
        
        return res;
    }
};