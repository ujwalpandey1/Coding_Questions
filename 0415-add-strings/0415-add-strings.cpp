class Solution {
public:
    string addStrings(string num1, string num2) {
    vector<int>ans(num1.size()+num2.size(),0);
    if(num1=="0") return num2;
        if(num2=="0") return num1;
      int n=num1.size();
        int m=num2.size();
         int i=n-1;
        int j=m-1;
        
        int sum;
        int p=ans.size();
        int k=p-1;
        while(i>=0||j>=0){
            int x=(i>=0)?num1[i]-'0':0;
            int y=(j>=0)?num2[j]-'0':0;
            int sum=x+y+ans[k];
            ans[k]=sum%10;
            ans[k-1]+=sum/10;
            i--;j--; k--;
            
        }
        
       for(int i=0;i<p;i++){
           if(ans[i]==0){
               ans.erase(ans.begin()+i);
               i--;
           }
           else break;
       }
        string res="";
        if(ans.size()==0) return "0";
        for(int i=0;i<ans.size();i++){
            res+=to_string(ans[i]);
        }
        return res;
    }
};