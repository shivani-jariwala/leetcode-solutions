class Solution {
private:
    bool findByBinarySearch(vector<int>arr, int target) {
        int low =0, high = arr.size()-1;
        while(low<=high) {
            int mid = (low+high)/2;
            if(arr[mid]==target) return true;
            else if(arr[mid]>target) high=mid-1;
            else low = mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++) {
            if(matrix[i][0]<=target && target<=matrix[i][matrix[i].size()-1]){
                return findByBinarySearch(matrix[i], target);
            }
        }
        return false;
    }
};