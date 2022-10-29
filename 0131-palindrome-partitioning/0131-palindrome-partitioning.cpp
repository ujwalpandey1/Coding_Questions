class Solution {
public:
    bool isPal(string str){
        int i=0;
        int j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>>&ans,vector<string>&temp,string s, int i){
        if(i==s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPal(s.substr(i,j-i+1))){
                temp.push_back(s.substr(i,j-i+1));
                solve(ans,temp,s,j+1);
                temp.pop_back();
            }
                
        }
    }
    vector<vector<string>> partition(string s) {
      vector<vector<string>>ans;
        vector<string>temp;
        solve(ans,temp,s,0);
        return ans;
    }
};