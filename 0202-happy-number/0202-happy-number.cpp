class Solution {
private:
    int computeSquare(int n){
        int sum=0;
        while(n>0){
            int rem = n%10;
            sum += rem*rem;
            n = n/10;
        }
        return sum;
    };
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n!=1){
            if(visited.count(n)) return false;
            visited.insert(n);

            n = computeSquare(n);
        }
        return true;
    }
};