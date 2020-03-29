/**
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");   
trie.search("app");     // 返回 true
说明:

你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-trie-prefix-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
**/

class TrieNode {
public:
    TrieNode()
    {
        for (int i = 0; i < children.size(); i++) {
            children[i] = nullptr;
        }
    }

    ~TrieNode()
    {
        for (int i = 0; i < children.size(); i++) {
            if (children[i] != nullptr) {
                delete children[i];
            }
        }
    }

    string s;
    vector<TrieNode*> children{26};
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* parent = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (parent->children[index] == nullptr) {
                TrieNode* node = new TrieNode();
                parent->children[index] = node;
            }
            parent = parent->children[index];
        }
        parent->s = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* parent = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (parent->children[index] == nullptr) {
                return false;
            }
            parent = parent->children[index];
        }
        return !parent->s.empty();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* parent = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (parent->children[index] == nullptr) {
                return false;
            }
            parent = parent->children[index];
        }
        return true;
    }
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */