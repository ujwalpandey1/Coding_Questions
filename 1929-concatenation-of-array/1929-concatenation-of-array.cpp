class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans;

        for(int i = 0;i< len ;i++)
        {
            ans.push_back(nums[i]);
        }

        for(int i = 0; i< len;i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};