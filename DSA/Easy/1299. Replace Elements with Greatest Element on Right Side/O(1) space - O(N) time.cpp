class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxm = -1;
        for(int i = arr.size()-1;i >= 0;i--){
            int cur = arr[i];
            arr[i] = maxm;
            maxm = max(maxm, cur);
        }
        return arr;
    }
};
