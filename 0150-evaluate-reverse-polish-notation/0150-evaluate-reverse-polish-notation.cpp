class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        for(int i=0;i<tokens.size();i++){
          if(st.size()>0){  
           if(tokens[i]=="*"||tokens[i]=="/"||tokens[i]=="-"||tokens[i]=="+"){
               long long int num1=st.top();
               st.pop();
               long long int num2=st.top();
               st.pop();
               if(tokens[i]=="*"){
                   st.push(num1*num2);
               }
               if(tokens[i]=="/"){
                   st.push(num2/num1);
               }
               if(tokens[i]=="-"){
                   st.push(num2-num1);
               }
               if(tokens[i]=="+"){
                   st.push(num1+num2);
               }
           }
              else {
                  st.push(stoi(tokens[i]));
              }
        }
            else st.push(stoi(tokens[i]));
    }
        return st.top();
    }
};