class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt = 0, rank = 0;
        for(auto e: nums){
            cnt += e == target;
            rank  += e < target;
        }
        vector<int> res;
        while(cnt--){
            res.push_back(rank++);
        }
        return res;
    }
};