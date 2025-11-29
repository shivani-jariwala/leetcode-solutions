struct TrieNode {
    bool isEnd;
    TrieNode* links[26];
    TrieNode() {
        isEnd = false;
        for(int i=0; i<26; i++) {
            links[i]=nullptr;
        }
    };
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root= new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char &w: word) {
            if(!curr->links[w-'a']){
            //doesn't exists
                curr->links[w-'a'] = new TrieNode();
            }
            curr = curr->links[w-'a'];
        }
        curr->isEnd=true;
    }

    bool helper(int idx, string &word, TrieNode* curr){
        //base
        if(curr==nullptr) return false;
        if(idx == word.length()) {
            return curr->isEnd;
        }
        if(word[idx]=='.'){
            for(int i=0;i<26;i++) {
                if(helper(idx+1,word,curr->links[i])) return true;
            }
        }else{
            if(helper(idx+1,word,curr->links[word[idx]-'a'])) return true;
        }
        return false;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        // for(char& c:word){
        //     if(curr->links[c-'a']==nullptr) return false;
        //     curr=curr->links[c-'a'];
        // }
        // return curr->isEnd;
        return helper(0, word, curr);
    }
};
