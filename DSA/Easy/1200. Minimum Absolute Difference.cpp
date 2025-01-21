class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        int dif = abs(arr[1] - arr[0]);

        result.push_back({arr[0], arr[1]});
        int current_dif = 0;
        for(int i = 1;i < n-1;i++){
            current_dif = abs(arr[i+1]-arr[i]);
            if(current_dif < dif) {
                dif = current_dif;
                result.clear();
                result.push_back({arr[i], arr[i+1]});
            } else if (dif == current_dif){
                result.push_back({arr[i], arr[i+1]});
            }
        }

        return result;
    }
};
