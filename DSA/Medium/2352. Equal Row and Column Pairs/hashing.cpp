class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> counter;
        for(int i = 0;i < grid.size();i++){
            counter[grid[i]]++;
        }
        int count = 0;
        for(int i = 0;i < grid.size();i++){
            vector<int> temp;
            for(int j = 0;j < grid.size();j++){
                temp.push_back(grid[j][i]);
            }
            if(counter[temp] > 0) count += counter[temp];
        }
        return count;
    }
};
