class Solution {
private: 
    void reverseFun(vector<int>& nums, int start, int end) {
        while(start<=end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        if(n<=1) return;
        k = k%n;
        reverseFun(nums, n-k, n-1);
        reverseFun(nums, 0, n-k-1);
        reverseFun(nums, 0, n-1);
    }
};