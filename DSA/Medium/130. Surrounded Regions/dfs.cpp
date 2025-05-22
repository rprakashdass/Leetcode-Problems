class Solution {
    int m, n;
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    bool isValid(const int i, const int j){
        return (i >= 0 && j >= 0 && i < m && j < n);
    }
    void dfs(vector<vector<char>>& board, int i, int j){
        if(!isValid(i, j) || board[i][j] != 'O') return;
        board[i][j] = 'V';
        for(auto [dx, dy] : dir){
            dfs(board, i + dx, j + dy);
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for(int i = 0;i < m;i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for(int j = 0;j < n;j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(board[i][j] == 'V') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O'){
                     board[i][j] = 'X';
                }
            }
        }
    }
};
