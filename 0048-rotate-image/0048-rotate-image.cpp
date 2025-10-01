class Solution {
private: 
    void reverseFun(vector<int>& arr){
        int p1=0, p2=arr.size()-1;
        while(p1<p2){
            swap(arr[p1],arr[p2]);
            p1++;
            p2--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose the matrix and then reverse
        for(int i=0; i<=(int)matrix.size()-2; i++){
            for(int j=i+1; j<=matrix.size()-1; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //now reverse it
        for(int i=0;i<matrix.size();i++){
            reverseFun(matrix[i]);
        }
    }
};