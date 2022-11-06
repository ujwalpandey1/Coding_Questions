class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(words[i][0]!=words[i][1]){
                string temp=words[i];
                reverse(temp.begin(),temp.end());
                if(mp.find(temp)!=mp.end()&&mp[temp]>0&&mp[words[i]]>0){
                    ans+=4;
                    mp[temp]--;
                     mp[words[i]]--;
                }
            }
            else{
                if(mp[words[i]]>=2){
                    ans+=4;
                    mp[words[i]]-=2;
                }
            }
        }
        for(auto i:mp){
            string temp=i.first;
            if(temp[0]==temp[1]&&i.second>0){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};