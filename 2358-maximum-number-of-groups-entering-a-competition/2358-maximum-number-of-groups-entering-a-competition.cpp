class Solution {
public:
    int maximumGroups(vector<int>& grades) {
      
        int i=0;
        int k=1;
        int count=1;
        while(i<=grades.size()){
            i+=k;
            k++;
          if(i<=grades.size())  count++;
        }
         return count-1;
    
    }
};