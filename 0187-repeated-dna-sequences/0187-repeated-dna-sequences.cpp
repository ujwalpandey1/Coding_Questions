class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        string temp="";
        unordered_map<string,int>mp;
        while(j<n){
            temp+=s[j];
            if(j-i+1<10) j++;
            else if(j-i+1==10){
                mp[temp]++;
                 temp.erase(temp.begin());
               i++;
                j++;
                
            }
        }
        vector<string>ans;
        for(auto i:mp){
            if(i.second>1) ans.push_back(i.first);
        }
        return ans;
    }
};