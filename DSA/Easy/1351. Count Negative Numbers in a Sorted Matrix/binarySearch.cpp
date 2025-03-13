class Solution {
public:
    int search(vector<int>& grid, int n){
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(grid[mid] >= 0){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return n - left;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;
        for(int i = 0;i < m;i++){
            count += search(grid[i], n);
        }
        return count;
    }
};
