class Solution {
private:
    void computePrefixAndSuffixMax(vector<int>& height, vector<int>& pMax, vector<int>& sMax) {
        int n = height.size();
        for(int i=1; i<n; i++) {
            pMax[i] = max(pMax[i-1], height[i]);
            sMax[n-i-1] = max(sMax[n-i], height[n-i-1]);
        }
    }
public:
    int trap(vector<int>& height) {
        //    [0,1,0,2,1,0,1,3,2,1,2,1]
        //p = [0,1,1,2,2 2 2 3 3 3 3 3]
        //s=  [3 3 3 3 3 3 3 3 3 2 2 2 1]
        int n = height.size();
        int storage=0;
        int total=0;
        vector<int> pMax(n);
        pMax[0] = height[0];
        vector<int> sMax(n);
        sMax[n-1] = height[n-1];
        computePrefixAndSuffixMax(height, pMax, sMax);
        for(int i=0; i<n; i++) {
            int storage = min(pMax[i],sMax[i])-height[i];
            if(storage>0) total+=storage; 
        }
        return total;
    }
};