class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
       map<char,string>mp;
        vector<string>str;
        stringstream ss(s);
        string temp;
        while(ss>>temp){
            str.push_back(temp);
        }
        int m=str.size();
        if(n!=m)  return false;
        for(int i=0;i<pattern.size();i++){
            mp[pattern[i]]=str[i];
        }
        set<string>st;
        for(auto i:str){
            st.insert(i);
        }
        if(mp.size()!=st.size()) return false;
        for(int i=0;i<n;i++){
            if(mp[pattern[i]]!=str[i]) return false;
        }
        return true;
    }
};