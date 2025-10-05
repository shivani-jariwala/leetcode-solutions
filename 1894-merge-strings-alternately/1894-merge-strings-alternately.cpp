class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int total = word1.length() + word2.length();
        string str="";
        for(int i=0;i<total;i++){
            if(i<word1.length()){
                str+=word1[i];
            }
            if(i<word2.length()){
                str+=word2[i];
            }
        }
        return str;
    }
};