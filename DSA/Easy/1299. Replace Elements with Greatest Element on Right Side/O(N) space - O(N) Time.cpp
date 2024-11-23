class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res;
        for(int i = 0;i<arr.size()-1;i++){
            auto maxm = *max_element(arr.begin()+i+1, arr.end());
            res.push_back(maxm);
        }
        res.push_back(-1);
        return res;
    }
};
