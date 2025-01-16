class Solution {
private:
    bool isValid(vector<vector<char>>& board, int row, int col, char num){
        for(int i = 0;i < 9;i++){
            if(board[i][col] == num) return false;
            if(board[row][i] == num) return false;
        }
        int startRow = row/3 * 3;
        int startCol = col/3 * 3;
        for(int i = 0;i < 3;i++){
            for(int j = 0;j < 3;j++){
                if(board[startRow+i][startCol+j] == num)    
                    return false;
            }
        }
        return true;
    }
    bool sudokoSolver(vector<vector<char>>& board) {
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.'){
                    for(char num = '1';num <= '9';num++){
                        if(isValid(board, i, j, num)){
                            board[i][j] = num;
                            if(sudokoSolver(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        sudokoSolver(board);
    }
};
