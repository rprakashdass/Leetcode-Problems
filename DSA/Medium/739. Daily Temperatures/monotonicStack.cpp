class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> stq;
        for(int i = n-1;i >= 0;i--){
            while(!stq.empty() && temperatures[stq.top()] <= temperatures[i]){
                stq.pop();
            }
            if(!stq.empty()){
                result[i] = stq.top() - i;
            }
            stq.push(i);
        }
        return result;
    }
};
