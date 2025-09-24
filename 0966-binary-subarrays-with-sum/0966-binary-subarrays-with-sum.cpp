class Solution {
private: 
    int computeSumWithGoal(vector<int>& arr, int goal){
        if(goal>arr.size()) return 0;
        if(goal<0) return 0;
        int l=0, r=0;
        long long sum=0;
        int cnt=0;
        while(r<arr.size()) {
            sum += arr[r];
            while(sum>goal){
                sum = sum - arr[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return computeSumWithGoal(nums, goal) - computeSumWithGoal(nums, goal-1);
    }
};