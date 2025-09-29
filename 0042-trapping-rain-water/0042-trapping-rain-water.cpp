class Solution {
public:
    int trap(vector<int>& height) {
        //TC=o(n) and SC=o(1) 2-pointer approach
        int n=height.size();
        int low=0, high=n-1, lMax=0, rMax=0, total=0;
        while(low<=high) {
            if(height[low]<=height[high]){
                //low is small therefore move it
                if(lMax>height[low]){
                    total += lMax - height[low];
                }else{
                    lMax = height[low];
                }
                low++;
            }else{
                //high is small therefore move it
                if(rMax>height[high]){
                    total += rMax - height[high];
                }else{
                    rMax = height[high];
                }
                high--;
            }
        }
        return total;
    }
};