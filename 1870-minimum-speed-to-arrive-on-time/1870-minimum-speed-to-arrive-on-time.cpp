class Solution {
public:
    bool check(vector<int>dist,int mid,double hour){
       
        double count=0;
        for(int i=0;i<dist.size()-1;i++){
           
            count+=ceil((double)dist[i]/mid);
           
        }
        count+=(double)dist.back()/mid;
        return count<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
       
        int l=1;
        int r=1e9;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(dist,mid,hour)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};