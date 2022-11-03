class Solution {
public:
     
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        
       vector<int>ans;
          
          sort(potions.begin(),potions.end());
             int i=0;
            
         while(i<n){   
            long long key=ceil(double(success*1.0/spells[i]));
            int  x=lower_bound(potions.begin(),potions.end(),key)-potions.begin();
             int res=potions.size()-x;
            ans.push_back(res);
            i++;
        }
        
      
        return ans;
    }
};