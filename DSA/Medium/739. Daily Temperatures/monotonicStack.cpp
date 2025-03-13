class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stq;
        for(int i = temperatures.size()-1;i >= 0;i--){
            while(!stq.empty() && stq.top().first <= temperatures[i]){
                stq.pop();
            }
            int topIndex = i;
            if(!stq.empty()){
                topIndex = stq.top().second;
            }
            stq.push(make_pair(temperatures[i], i));
            temperatures[i] = topIndex - i;
        }
        return temperatures;
    }
};
