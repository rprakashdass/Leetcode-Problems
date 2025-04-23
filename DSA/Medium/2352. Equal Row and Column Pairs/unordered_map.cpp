class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> counter;
        for(int i = 0;i < grid.size();i++){
            string temp = "";
            for(int j = 0;j < grid.size();j++){
                temp = to_string(grid[i][j]) + " " + temp;
            }
            counter[temp]++;
        }
        int count = 0;
        for(int i = 0;i < grid.size();i++){
            string temp = "";
            for(int j = 0;j < grid.size();j++){
                temp = to_string(grid[j][i]) + " " + temp;
            }
            if(counter[temp] > 0) {
                count += counter[temp];
            }
        }
        return count;
    }
};
