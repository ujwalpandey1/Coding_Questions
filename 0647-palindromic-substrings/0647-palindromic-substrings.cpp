class Solution {
public:
     bool isPalindrome(string str )
    {
        string s1=str;
         reverse(str.begin(),str.end());
         return s1==str;
    }
    int countSubstrings(string s) {
        int count=0;
       for(int i=0;i<s.size();i++){
        int l=i;
        int r=i;
       
        while(l>=0&&r<s.size()&&s[l]==s[r]){
            string temp=s.substr(l,r-l+1);
            if(isPalindrome(temp)) count++;
                l--;
                r++;
            
        }
        
        l=i;
        r=i+1;
        
        while(l>=0&&r<s.size()&&s[l]==s[r]){
           string temp= s.substr(l,r-l+1);
            if(isPalindrome(temp)) count++;
                l--;r++;
            
        }
        } 
        return count;
    }
};