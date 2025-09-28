class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq; //maxheap
        string ans="";
        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});
        while(!pq.empty()) {
            pair<int, char> first = pq.top();
            pq.pop();
            if(ans.length()>=2 && ans[ans.size()-1]==first.second && ans[ans.size()-2]==first.second) {
                if(pq.empty()) break;
                auto [freq, x] = pq.top();
                pq.pop();
                ans = ans + x;
                freq--;
                if(freq>0) pq.push({freq, x});
            }else{
                ans = ans + first.second;
                first.first--;
            }
            if(first.first>0){
                pq.push({first.first, first.second});
            }
        }
        return ans;
    }
};