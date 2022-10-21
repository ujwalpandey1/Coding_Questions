class Solution {
public:
    double findMaxAverage(vector<int>& nums, int l) {
        double sum=0;
        double k=l;
        int i=0;
        int j=0;
        double max_average=INT_MIN;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<k) j++;
            else if(j-i+1==k){
                double temp=sum/k;
               
              if(temp>max_average){
                  max_average=temp;
              }
                sum-=nums[i];
                i++;
                j++;    
            }
        }
        return max_average;
    }
};