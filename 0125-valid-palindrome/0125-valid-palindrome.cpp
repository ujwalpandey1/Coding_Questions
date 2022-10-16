class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            s[i]=tolower(s[i]);
        }
        string ans="";
        for(auto i:s){
            if((i>=97&&i<=122)||((i-'0')>=0&&(i-'0')<=9)){
                ans+=i;
            }
        }
        string str=ans;
        reverse(ans.begin(),ans.end());
        return ans==str;
    }
};