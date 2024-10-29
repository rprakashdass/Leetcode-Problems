class Solution {
public:
    int maxProfit(vector<int>& arr) {

        int maxm = 0;
        int minm = INT_MAX;
        int n = arr.size();

        for(int j = 0;j < n;j++){
            minm = min(minm, arr[j]);
            maxm = max(maxm, arr[j] - minm);
        }

        return maxm;
    }
};

// Time limit error
class Solution {
public:
    int maxProfit(vector<int>& arr) {

        int maxm = 0;
        int n = arr.size();
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(arr[i] <= arr[j]){
                    maxm = max(maxm, abs(arr[i]-arr[j]));
                }
            }
        }
        return maxm;
    }
};
