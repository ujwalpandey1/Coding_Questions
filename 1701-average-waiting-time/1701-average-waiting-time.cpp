class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int start=customers[0][0];
        int free=start+customers[0][1];
        double curtime=free-start;
        for(int i=1;i<customers.size();i++){
            int s=customers[i][0];
            int temp=max(free-customers[i][0],0);
            free=customers[i][0]+customers[i][1]+temp;
            curtime+=free-s;
        }
        return curtime/(double)customers.size();
    }
};