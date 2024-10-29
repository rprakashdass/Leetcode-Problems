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

// Opmal Approach

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int m = matrix.size();

        int left = 0;
        int right = n*m - 1;

        while(left <= right) {
            int mid = (left + right) / 2;
            int r = mid / n;
            int c = mid % n;
            
            if( matrix[r][c] == target)
                return true;
            else if ( target < matrix[r][c] )
                right = mid - 1;
            else
                left = mid + 1;
        }


        return false;
    }
};
