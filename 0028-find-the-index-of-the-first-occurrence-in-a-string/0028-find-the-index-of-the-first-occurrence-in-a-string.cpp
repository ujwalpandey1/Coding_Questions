class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[0]){
                int count=1;
                for(int j=1;j<m;j++){
                    if(needle[j]==haystack[i+j]) count++;
                    else break;
                }
                if(m==count) return i;
            }
        }
        return -1;
    }
};