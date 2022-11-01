class Solution {
public:
    bool check(vector<int>time,long long  mid,int totalTrips){
        long long int sum=0;
       long long int count=0;
        for(int i=0;i<time.size();i++){
           count+=(long)mid/time[i];
           
        }
        return count>=totalTrips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
       long long s=*min_element(time.begin(),time.end());
       long long e=s*totalTrips;
        long long ans=-1;
        while(s<=e){
           long long mid=s+(e-s)/2;
            if(check(time,mid,totalTrips)) {
                ans=mid;
                e=mid-1;
                
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};