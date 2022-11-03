class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long int sum=0;
        for(auto i:chalk) sum+=i;
      
            long long int find=k%sum;
            for(int i=0;i<chalk.size();i++){
                 if(find<chalk[i]) {
               return i;
                }
                else {
                    find-=chalk[i];
                }
            }
            
        return chalk.size()-1;
        
    }
};