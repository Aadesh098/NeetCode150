// Word Search - 2
// https://leetcode.com/problems/word-search-ii/

class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(string word) {
        TrieNode* node = root;
        int curr = 0;
        for (int i = 0; i < word.size(); i++) {
            curr = word[i] - 'a';
            if (node->children[curr] == NULL) {
                node->children[curr] = new TrieNode();
            }
            node = node->children[curr];
        }
        node->isWord = true;
    }
    void search(vector<vector<char>>& board, int i, int j, int m, int n,
                TrieNode* node, string word, vector<string>& result) {
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#') {
            return;
        }
        char c = board[i][j];
        node = node->children[c - 'a'];
        if (node == NULL) {
            return;
        }
        word += board[i][j];
        if (node->isWord) {
            result.push_back(word);
            node->isWord = false;
        }
        board[i][j] = '#';
        search(board, i - 1, j, m, n, node, word, result);
        search(board, i + 1, j, m, n, node, word, result);
        search(board, i, j - 1, m, n, node, word, result);
        search(board, i, j + 1, m, n, node, word, result);
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& board,vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        int m = board.size();
        int n = board[0].size();
        TrieNode* node = root;
        vector<string> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j, m, n, node, "", result);
            }
        }
        return result;
    }
};