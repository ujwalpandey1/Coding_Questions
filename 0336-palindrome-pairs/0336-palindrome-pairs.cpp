#include<bits/stdc++.h>
class Solution {
public:
    
      bool isPalindrome(string& s) {   
          int l=0, r=s.size()-1;
          while(l<r){if(s[l++]!=s[r--]) return false;}
          return true; 
    }


    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> ans;
        int n = words.size();
      //remove TLE
        if(n<2) return ans;
        unordered_map<string, int> m;
        for(int i=0;i<n;++i){
            
            string s= words[i];
            reverse(s.begin(),s.end());
            m[s]=i;
        }
      
        for(int i=0; i<n; ++i){
            for(int j=0; j<=words[i].size(); ++j){
               string str1=words[i].substr(0,j);
                string str2=words[i].substr(j);
                if(m.count(str1)&&isPalindrome(str2)&&m[str1]!=i) ans.push_back({i,m[str1]});
                 if(!str1.empty()&&m.count(str2)&&isPalindrome(str1)&&m[str2]!=i) ans.push_back({m[str2],i});
            }            
        }
       
        return ans;
    }

   
    
};