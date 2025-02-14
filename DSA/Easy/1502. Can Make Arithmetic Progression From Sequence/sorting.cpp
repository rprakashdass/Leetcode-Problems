class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), diff = abs(arr[1] - arr[0]);
        for(int i = 1;i < n-1;i++){
            if(diff != abs(arr[i] - arr[i+1])) return false;
        }
        return true;
    }
};
