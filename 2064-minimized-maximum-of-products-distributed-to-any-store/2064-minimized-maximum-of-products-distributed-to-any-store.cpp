class Solution {
public:
    bool check(vector<int>&quantities,int n,int mid){
        int sum=0;
        for(auto i:quantities){
            sum+=ceil(double(i)/double(mid));
        }
        return sum<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1;
        int end=1e5;
        int ans=0;
        while(start<=end){
            int mid=(start)+(end-start)/2;
            if(check(quantities,n,mid)){

            ans=mid;
            end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return ans;
    }
};