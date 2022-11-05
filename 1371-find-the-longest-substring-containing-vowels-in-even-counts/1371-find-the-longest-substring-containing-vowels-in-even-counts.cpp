class Solution {
public:
    int findTheLongestSubstring(string s) {
       vector<int>mask(32,-1);
        int m=0;
        int maxlen=0;
      
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='u'||s[i]=='i'){
                m=m^((s[i]-'a')+1);
            }
            else{
                m=m^0;
            }
            if(m!=0&&mask[m]==-1){
                mask[m]=i;
            }
            else{
                maxlen=max(maxlen,i-mask[m]);
            }
        }
        return maxlen;
    }
};