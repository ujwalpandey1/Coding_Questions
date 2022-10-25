class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int key=nums[i];
            int count=0;
            while(i<nums.size()&&nums[i]==key){

                count++;
                i++;
                
            }
            i--;
           while(count>2){
               nums.erase(nums.begin()+i);
               count--;
               i--;
           }
        }
        return nums.size();
    }
};