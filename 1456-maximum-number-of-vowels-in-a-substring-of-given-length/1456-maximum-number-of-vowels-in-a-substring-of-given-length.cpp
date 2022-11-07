class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0;
        int j=0;
        int n=s.size();
        int count=0;
        int ans=0;
        while(j<n){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') count++;
            
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                ans=max(ans,count);
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') count--;
                i++;
                j++;
            }
        }
        return ans;
    }
};