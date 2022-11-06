class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char>st(jewels.begin(),jewels.end());
        int ans=0;
        for(auto i:stones){
            if(st.find(i)!=st.end()) ans++;
        }
        return ans;
    }
};