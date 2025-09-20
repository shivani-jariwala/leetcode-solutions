class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0, r=0, cnt = 0;
        int n = fruits.size();
        map<int,int> mpp;
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>2){
                while(mpp.size()>2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                    l++;
                }
            } else {
                cnt = max(cnt, r-l+1);
            }
            r++;
        }
        return cnt;
    }
};