class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> stq;
        for(char ch: s){
            if(!stq.empty() && stq.top().first == ch){
                if(stq.top().second == k-1){
                    stq.pop();
                } else {
                    stq.top().second += 1;
                }
            } else {
                stq.push(make_pair(ch, 1));
            }
        }
        string result;
        for(int i = stq.size()-1;i >= 0;--i){
            result.append(stq.top().second, stq.top().first);
            stq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
