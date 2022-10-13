class Solution {
public:
   // O(n^2(logn)) Time Complexity O(1) Space
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        if(k==1) return low;
        if(k==n*n) return high;
        while(low<high){
            int mid=(low+(high-low)/2);
            int count=0;
            for(int i=0;i<n;i++){
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<k) low=mid+1;
            else high=mid;
        }
        return low;
    }
};