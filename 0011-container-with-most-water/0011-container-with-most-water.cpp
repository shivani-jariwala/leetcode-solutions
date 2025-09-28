class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1, maxi=INT_MIN;
        while(left<=right){
            int area=(right-left)*min(height[left],height[right]);
            maxi=max(maxi,area);
            if(height[left]<height[right]) left++;
            else right--;
        }
        return maxi;
    }
};