class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(59);
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i;j++){
              dp[i]=max({dp[i],dp[i-j]*dp[j],dp[j]*(i-j),dp[i-j]*j,(i-j)*j});
            }
        }
        return dp[n];
    }
};