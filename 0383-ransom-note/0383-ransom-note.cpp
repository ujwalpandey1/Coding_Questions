class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       if(magazine.size()<ransomNote.size()) return false;
      unordered_map<char,int>mp;
        for(auto i:magazine){
            mp[i]++;
        }
        
        for(int i=0;i<ransomNote.size();i++){
           if(mp[ransomNote[i]]==0) return false;
            else{
                mp[ransomNote[i]]--;
            }
        }
        return true;
    }
};