class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(k<=1)  return n;
        if(n==0||n<k) return 0;
        
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int i=0;
        while(i<n&&mp[s[i]]>=k) i++;
        if(i>=n-1) return i;
        int l1=longestSubstring(s.substr(0,i),k);
       
        while(i<n&&mp[s[i]]<k) i++;
        
        int l2=(i<n)?longestSubstring(s.substr(i),k):0;
        return max(l1,l2);
    }
};