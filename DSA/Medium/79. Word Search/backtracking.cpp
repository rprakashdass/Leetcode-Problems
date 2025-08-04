class Solution {
    int m, n;
    vector<int> x = {0, 0, 1, -1};
    vector<int> y = {1, -1, 0, 0};
public:
    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }
    bool backtrack(vector<vector<char>>& board, string &word, int wordIndex, int i, int j) {
        if(wordIndex == word.size()) return true;
        if(!isValid(i, j) || board[i][j] != word[wordIndex]) return false;

        char letter = board[i][j];
        board[i][j] = '0';
        
        for(int d = 0;d < 4;d++) {
            int dx = i + x[d], dy = j + y[d];
            if(backtrack(board, word, wordIndex+1, dx, dy)) return true;
        }
        
        board[i][j] = letter;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(board[i][j] != word[0]) continue;
                if(backtrack(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
