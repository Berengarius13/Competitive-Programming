struct Node{
    Node* link[26];
    bool flag = false;
    
    bool contain_key(char ch){
        if(link[ch-'a'] != NULL)
            return true;
        else 
            return false;
    }
    void put(char ch, Node* node){
        link[ch - 'a'] = node;
    }
    
};
class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node * node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->contain_key(word[i])){ // Insert if ther are no nodes
                node->put(word[i], new Node());
            }
            node = node->link[word[i] - 'a']; // Move to next node
        }
        node->flag = true; // Set last node as true
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->contain_key(word[i])) return false;
            node = node->link[word[i] - 'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++){
            if(!node->contain_key(prefix[i])) return false;
            node = node->link[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */