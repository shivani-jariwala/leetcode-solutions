class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum =0, rSum = 0,rIndex = cardPoints.size()-1, maxi =0;
        for(int i=0; i<k; i++) {
            lSum += cardPoints[i];
        }
        maxi = lSum;
        for(int i = k-1; i>=0; i--) {
            lSum = lSum - cardPoints[i];
            rSum = rSum + cardPoints[rIndex];
            maxi = max(maxi, lSum + rSum);
            rIndex--;
        }
        return maxi;
    }
};