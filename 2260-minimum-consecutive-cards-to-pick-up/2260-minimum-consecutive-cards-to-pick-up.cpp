class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans=INT_MAX;
      unordered_map<int,vector<int>>mp;
        for(int i=0;i<cards.size();i++){
           mp[cards[i]].push_back(i);
        }
        for(auto i:mp){
            if(i.second.size()>1){
               for(int x=1;x<i.second.size();x++){
                   ans=min(ans,i.second[x]-i.second[x-1]+1);
               }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};