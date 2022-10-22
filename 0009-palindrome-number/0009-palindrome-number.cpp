class Solution {
public:

    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x==0) return true;
        int power=floor(log10(x)+1);
        power--;
        
        int num=x;
        long long int num2=0;
        while(num>0){
            int digit=num%10;
            num=num/10;
            num2=num2+(digit*pow(10,power));
            power--;
        }
       
        return x==num2;
    }
};