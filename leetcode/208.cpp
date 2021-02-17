// O(N)

class Trie {
public:
    bool isEnd;
    Trie* trie[26];
    
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for (auto& item : trie) item = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;

        for (auto ch : word) {
            if (node->trie[ch - 'a'] == nullptr) {
                node->trie[ch - 'a'] = new Trie();
                node = node->trie[ch - 'a'];
            } else {
                node = node->trie[ch - 'a'];
            }
        }
        
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto ch : word) {
            if (node->trie[ch - 'a'] == nullptr) return false;
            else {
                node = node->trie[ch - 'a'];
            }
        }
        
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto ch : prefix) {
            node = node->trie[ch - 'a'];
            if (node == nullptr) return false;
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