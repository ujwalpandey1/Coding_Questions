class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid>0&&mid<arr.size()-1){
                int next=mid+1;
                int prev=mid-1;
                if(arr[mid]>arr[next]&&arr[mid]>arr[prev]){
                    return mid;
                }
                else if(arr[mid]<arr[next]) l=mid+1;
                else r=mid-1;
            }
            else if(mid==0){
                if(arr[mid]>arr[mid+1])  return mid;
                else return mid+1;
            }
            else if(mid==arr.size()-1){
                if(arr[mid]>arr[mid-1]) return mid;
                else return mid-1;
            }
            
        }
        return 0;
    }
};