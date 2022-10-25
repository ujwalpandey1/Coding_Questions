class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==0) return 0;
        int left=0;
        int ans=0;
        int right=height.size()-1;
        while(left<=right){
            int h=min(height[left],height[right]);
            int width=right-left;
            int area=h*width;
            ans=max(ans,area);
            if(height[left]<height[right]){
                left++;
                
            }
            else{
                right--;
            }
        }
        return ans;
    }
};