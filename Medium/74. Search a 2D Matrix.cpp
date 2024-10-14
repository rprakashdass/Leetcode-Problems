// Brute Force Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();
        for(int i = 0;i < m;i++) {
            if( target <= matrix[i][n-1] ){
                for( int j = 0;j < n;j++) {
                    if(matrix[i][j] == target)
                        return true;
                }
                return false;
            }

        }
        return false;
    }
};
