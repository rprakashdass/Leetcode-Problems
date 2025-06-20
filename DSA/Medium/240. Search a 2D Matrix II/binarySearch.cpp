class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int row, int target) {
        int left = 0, right = matrix[0].size();
        while(left <= right) {
            int mid = (left + right)/2;
            if(matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(int i = 0;i < matrix.size();i++) {
            if(matrix[i][0] > target) return false;
            if(matrix[i][n-1] >= target && binarySearch(matrix, i, target)) return true;
        }
        return false;
    }
};
