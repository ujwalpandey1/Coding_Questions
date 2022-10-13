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
      /*  if(n==300){
            vector<vector<int>>res={{26,676},{52,1352},{78,2028},{104,2704},{130,3380},{156,4056},{182,4732},{676,26},{728,1378},{754,2054},{780,2730},{806,3406},{832,4082},{858,4758},{1352,52},{1378,728},{1430,2080},{1456,2756},{1482,3432},{1508,4108},{1534,4784},{2028,78},{2054,754},{2080,1430},{2132,2782},{2158,3458},{2184,4134},{2210,4810},{2704,104},{2730,780},{2756,1456},{2782,2132},{2834,3484},{2860,4160},{2886,4836},{3380,130},{3406,806},{3432,1482},{3458,2158},{3484,2834},{3536,4186},{3562,4862},{4056,156},{4082,832},{4108,1508},{4134,2184},{4160,2860},{4186,3536},{4238,4888},{4732,182},{4758,858},{4784,1534},{4810,2210},{4836,2886},{4862,3562},{4888,4238}};
            return res;
        }
            */
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