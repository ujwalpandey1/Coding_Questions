class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        int ind=-1;
        int ind2=-1;
        int i=0;
        int j=0;
      
        int sum=0;
        while(j<customers.size()){
            sum+=customers[j]*grumpy[j];
           
            if(j-i+1<minutes) j++;
            else if(j-i+1==minutes){
                if(sum>ans){
                    ans=sum;
                    ind=i;
                    ind2=j;
                }
                sum-=customers[i]*grumpy[i];
                i++;j++;
            }
        }
        ans=0;
      if(ind==-1||ind2==-1){
          ind=0;
          ind2=customers.size()-1;
      }
        
        for(i=ind;i<=ind2;i++) ans+=customers[i];
         
            for( i=0;i<ind;i++){
                if(grumpy[i]==0){
                    ans+=customers[i];
                }
            }
       
            for( i=ind2+1;i<customers.size();i++){
                if(grumpy[i]==0){
                    ans+=customers[i];
                }
            }
        
        return ans;
    }
};