class Solution {
private: 
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int countVowelSubstrings(string word) {
        unordered_map<char, int> mpp;
        int j =0;
        int cnt = 0;
        int n = word.length();
        string vowel = "aeiou";
        for(char it: vowel) {
            mpp[it]=-1;
        }

        for(int i=0; i<n;i++) {
            if(!isVowel(word[i])) {
                //consonant
                j = i+1;
                for(char it: vowel) {
                    mpp[it]=-1;
                }
            }else{
                //vowel
                mpp[word[i]]=i;
                int min_last_seen = INT_MAX;
                for(char it: vowel ) {
                    min_last_seen = min(min_last_seen, mpp[it]);
                }
                if(min_last_seen>=j){
                    cnt += (min_last_seen-j+1);
                }
            }
        }
        return cnt;
    }
};