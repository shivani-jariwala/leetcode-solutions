class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            for(int j=i+1; j<nums.size(); j++) {
                long long newTarget = target-1ll*(nums[i]+nums[j]);
                int l = j+1;
                int r = nums.size()-1;
                while(l<r){
                    if(nums[l]+nums[r] < newTarget){
                        l++;
                    }else if(nums[l]+nums[r] > newTarget) {
                        r--;
                    }else{
                        vector<int> temp = {nums[i], nums[j], nums[l], nums[r]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                        l++;
                        r--;
                    }
                }
            }
        }
        for(auto it: st) {
            ans.push_back(it);
        }
        return ans;
    }
};