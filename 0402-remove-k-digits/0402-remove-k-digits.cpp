class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        if(num.size()<=k) return "0";
        for(int i=0;i<num.size();i++){
            
            while(st.size()>0&&st.top()>num[i]&&k>0)
            {
             st.pop();
             k--; 
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0'){ ans.erase(ans.begin()+i); i--;}
            else break;
        }
       
        if(ans=="") return "0";
        return ans;
    }
};