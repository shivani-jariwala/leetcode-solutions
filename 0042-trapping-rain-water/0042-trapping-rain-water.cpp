class Solution {
private: 
    vector<int> computePrefixMax(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMax(n);
        prefixMax[0]=height[0];
        for(int i=1; i<n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i-1]);
        }
        return prefixMax;
    }

    vector<int> computeSuffixMax(vector<int>& height) {
        int n = height.size();
        vector<int> suffixMax(n);
        suffixMax[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i+1]);
        }
        return suffixMax;
    }
public:
    int trap(vector<int>& height) {
        //O(N)
        int total=0;
            vector<int> pMax = computePrefixMax(height);
            vector<int> sMax = computeSuffixMax(height);
        for(int i=0; i<height.size(); i++) {
            int storage = min(pMax[i], sMax[i])-height[i];
            if(storage > 0){
                total += storage;  
            }
        }
        return total;
    }
};