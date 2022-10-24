class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0||c==1||c==2) return true;
       long long int i=0;
        long long int j=sqrt(c);
        while(i<=j){
           long long int mid=(i+j)/2;
            if(i*i+j*j==c) return true;
            else if(i*i+j*j<c) i++;
            else j--;
        }
        return false;
    }
};