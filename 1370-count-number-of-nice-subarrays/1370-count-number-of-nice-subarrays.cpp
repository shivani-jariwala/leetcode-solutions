class Solution {
private:
    int computeSumByGoal(vector<int>& arr, int goal) {
        int l=0, r=0, sum=0, cnt=0;
        while(r<arr.size()){
            sum += (arr[r]%2);
            while(sum>goal) {
                sum -= (arr[l]%2);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return computeSumByGoal(nums, k) - computeSumByGoal(nums, k-1);
    }
};