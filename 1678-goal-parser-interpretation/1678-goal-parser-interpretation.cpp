class Solution {
public:
    string interpret(string command) {
       string ans="";
        for(int i=0;i<command.size()-1;i++){
         if(command[i]!='('&&command[i]!=')')   ans+=command[i];
         else  if(command[i]=='('&&command[i+1]==')') ans+='o';
        }
        if(command[command.size()-1]!='('&&command[command.size()-1]!=')') ans+=command[command.size()-1];
        return ans;
    }
};