class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 1;row < n;row++) {
            for(int col = 0;col < n;col++) {
                int left = INT_MAX, right = INT_MAX;
                int straight = matrix[row-1][col];
                if(col-1 >= 0) left =  matrix[row-1][col-1];
                if(col+1 < n) right = matrix[row-1][col+1];
                matrix[row][col] += min(left, min(right, straight));
            }
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
