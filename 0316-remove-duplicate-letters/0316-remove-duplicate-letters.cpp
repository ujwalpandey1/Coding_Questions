class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>last;
        for(int i=0;i<s.size();i++){
            last[s[i]]=i;
        }
        unordered_map<char,int>visited;
        stack<char>st;
      for(int i=0;i<s.size();i++){
          if(visited[s[i]]==1) continue;
          while(st.size()>0&&s[i]<st.top()&&last[st.top()]>i) 
          {char x=st.top();
           visited[x]=0;
          st.pop();
          } 
          
         st.push(s[i]);
        visited[s[i]]=1;
      }
      
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
    
        reverse(ans.begin(),ans.end());
        return ans;
    }
};