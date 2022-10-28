class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
     int moves=0;
     int start=0;
        int i=1;
        while(1){
            
                start+=i;
                i++;
                moves++;
        
            
                if(start==target) return moves;
                
            
                else if(start>target&&(start-target)%2==0) return moves;
            
        }
        return 0;
    }
};