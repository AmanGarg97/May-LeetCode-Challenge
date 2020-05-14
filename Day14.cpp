// Question - Implement Trie (Prefix Tree)


/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
*/

// Solution
class Trie {
     Trie *children[26];
        bool isEndOfWord;
public:
    /** Initialize your data structure here. */
    Trie() {
       isEndOfWord = false;
       for(int i = 0 ; i < 26 ; i++) {
           children[i] = nullptr;
       }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * curr = this;

        for(int i = 0 ; i < word.length() ; i++) {
            if(curr -> children[word[i] - 'a'] == nullptr) {
                curr -> children[word[i] - 'a'] = new Trie();
            }
            curr = curr -> children[word[i] - 'a'];
        }
        curr -> isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * curr = this;

        for(int i = 0 ; i < word.length() ; i++) {
            if(curr -> children[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> children[word[i] - 'a'];
        }

        if(curr -> isEndOfWord) {
            return true;
        }
        else{
            return false;
        }
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
         Trie * curr = this;

        for(int i = 0 ; i < word.length() ; i++) {
            if(curr -> children[word[i] - 'a'] == nullptr) {
                return false;
            }
            curr = curr -> children[word[i] - 'a'];
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
