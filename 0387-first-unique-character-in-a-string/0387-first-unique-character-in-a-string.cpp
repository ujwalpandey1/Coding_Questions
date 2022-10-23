class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto i:mp){
            if(i.second.size()==1) {
                ans=min(ans,i.second[0]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};