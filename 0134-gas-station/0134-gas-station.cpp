class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0, totalCost=0, start=0, currGas=0;
        for(auto &it:gas) {
            totalGas+=it;
        }
        for(auto &it:cost) {
            totalCost+=it;
        }
        if(totalGas<totalCost) return -1;
        for(int i=0; i<gas.size(); i++) {
            currGas += (gas[i]-cost[i]);
            if(currGas<0){
                start = i+1;
                currGas =0;
            }
        }
        return start;
    }
};