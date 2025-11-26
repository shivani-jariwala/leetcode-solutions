class Solution {
public:
    int countVowelSubstrings(string word) {
        int n =word.length();
        unordered_map<char, int> mpp; // 'a':1
        int cnt = 0;
        for(int i =0; i<n; i++) {
            for(int j=i; j<n;j++){
                if(word[j]!='a' && word[j]!='e' && word[j]!='i' && word[j]!='o' &&  word[j]!='u') {
                    //not vowel
                    break;
                }else {
                    mpp[word[j]]++;
                    if(mpp['a']>=1 && mpp['e']>=1 && mpp['i']>=1 && mpp['o']>=1 && mpp['u']>=1) {
                        cnt ++;
                    }
                }
            }
            mpp.clear();
        }
        return cnt;
    }
};