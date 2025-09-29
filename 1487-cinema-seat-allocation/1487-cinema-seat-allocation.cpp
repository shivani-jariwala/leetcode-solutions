class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mpp; //row, reservedseats
        int ans=0;
        //start inserting into map
        for(auto &it1 : reservedSeats) {
            mpp[it1[0]].insert(it1[1]);
        }
        //iterate over the rows of the map
        for(auto it: mpp) {
            int isLeftOccupied=false, isMiddleOccupied=false, isRightOccupied=false;
            if(it.second.count(2)||it.second.count(3)||it.second.count(4)||it.second.count(5)){
                isLeftOccupied=true;
            }
            if(it.second.count(6)||it.second.count(7)||it.second.count(8)||it.second.count(9)){
                isRightOccupied=true;
            }
            if(it.second.count(4)||it.second.count(5)||it.second.count(6)||it.second.count(7)){
                isMiddleOccupied=true;
            }

            //only 2 cases 
            if(!isLeftOccupied && !isRightOccupied){
                //when we can fit 2 families
                ans +=2; // this means both right and left are empty
            }else {
                //we can fit only 1 family
                if(!isLeftOccupied || !isRightOccupied || !isMiddleOccupied) {
                    ans +=1;
                }
            }

        }
        ans += (n-mpp.size())*2;
        return ans;
    }
};