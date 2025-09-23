class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> vec;
        string ans;
        int l=0,r=0;
        while(r<n) {
            while(r<n && s[r]==' '){
                r++;
            }
            l=r;
            while(r<n && s[r]!=' '){
                r++;
            }
            string temp = s.substr(l, r-l);
            if(!temp.empty())
            vec.push_back(temp);
        }
        for(int i=vec.size()-1; i>=0; i--){
            ans += vec[i];
            if(i!=0){
                ans += ' ';
            }
        }
        return ans;
    }
};