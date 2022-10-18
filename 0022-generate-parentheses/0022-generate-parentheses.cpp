class Solution {
public:
    void solve(int open,int close,string out,vector<string>&ans){
            if(open==0&&close==0){
                ans.push_back(out);
                return ;
            }
        if(open!=0){
            string op=out+'(';
            solve(open-1,close,op,ans);
        }
        if(close>open){
            string op2=out+')';
            solve(open,close-1,op2,ans);
        }
        return ;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string out="";
        int open=n;
        int close=n;
        solve(open,close,out,ans);
        return ans;
    }
};