class Solution {
public:
 
    int maxProduct(vector<string>& words) {
        int ans=0;
        vector<set<int>>s(words.size());
        for(int i=0;i<words.size();i++){
            set<int>temp;
            for(auto x:words[i]){
                temp.insert(x-'a');    
            }
            s[i]=temp;
        }
        for(int i=0;i<words.size()-1;i++){
            for(int j=i+1;j<words.size();j++){
                int flag=1;
                  for(auto x:s[i]){
                      if(s[j].find(x)!=s[j].end()){
                          flag=0;
                          break;
                      }
                  }
                if(flag==1){
                    int res=words[i].size()*words[j].size();
                    ans=max(ans,res);
                }
                }
            }
        
        return ans;
    }
};