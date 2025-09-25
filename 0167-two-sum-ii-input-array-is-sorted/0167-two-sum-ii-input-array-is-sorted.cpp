class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //since it's sorted think about 2 pointer approach
        int left =0, right = numbers.size()-1;
        vector<int> ans;
        while(left<right){
            if(numbers[left] + numbers[right] > target){
                right--;
            }else if(numbers[left]+numbers[right]<target){
                left++;
            }else{
                //both are equal
                ans.push_back(left+1);
                ans.push_back(right+1);
                // ans.insert(ans.end(),{left+1, right+1});
                left++;
                right--;
            }
        }
        return ans;
    }
};