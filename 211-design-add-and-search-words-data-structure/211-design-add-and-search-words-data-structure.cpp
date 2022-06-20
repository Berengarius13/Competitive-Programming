
class Trie{
public:
    Trie *trieNodes [26];
    bool isEnd=false;
};
class WordDictionary {
public:
    Trie* root;
    WordDictionary() {
        root= new Trie();
    }
    
    void addWord(string word) {
        Trie* node=root;
        for (char c:word){
            if (node->trieNodes[c-'a']==NULL){
                node->trieNodes[c-'a']=new Trie();
            }
            node=node->trieNodes[c-'a'];
        }
        node->isEnd=true;
    }
    bool solve(string word, Trie* node){
        for (int i=0;i<word.size();i++){
            if (word[i]=='.'){
                for (char c='a';c<='z';c++){
                    if (node->trieNodes[c-'a']!=NULL && solve(word.substr(i+1),node->trieNodes[c-'a'])) return true;
                }
                return false;
            }
            else{
                if (node->trieNodes[word[i]-'a']==NULL) return false;
                node=node->trieNodes[word[i]-'a'];
            }
        }
        if (node->isEnd) return true;
        return false;
        
    }
    bool search(string word) {
        Trie* node=root;
        return solve(word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */