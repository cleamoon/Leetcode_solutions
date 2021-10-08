class Trie {
private:
    struct node {
        char ch;
        bool isWord = false;
        unordered_map<char, node*> m{};
        
        node(char _ch) : ch(_ch) { }
    };
    
    node* root = nullptr;

    
public:
    Trie() {
        root = new node('a');
    }
    
    void insert(string word) {
        node* cur = root;
        for (auto i = 0; i < word.length(); i++) {
            auto it = cur->m.find(word[i]);
            if (it != cur->m.end()) {
                cur = it->second;
            } else {
                cur->m.insert(make_pair(word[i], new node(word[i])));
                cur = cur->m.find(word[i])->second;
            }
            if (i == word.length()-1) {
                cur->isWord = true;
            }
        }
    }
    
    bool search(string word, bool isPref = false) {
        node* cur = root;
        for (auto i = 0; i < word.length(); i++) {
            auto it = cur->m.find(word[i]);
            if (it != cur->m.end()) {
                cur = it->second;
                if (i == word.length()-1) {
                    if (!isPref)
                        return cur->isWord; 
                    else
                        return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
