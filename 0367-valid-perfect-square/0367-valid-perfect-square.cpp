class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1||num==0) return true;
        for(long long int i=1;i<=num/2;i++){
            if(i*i==num) return true;
        }
        return false;
    }
};