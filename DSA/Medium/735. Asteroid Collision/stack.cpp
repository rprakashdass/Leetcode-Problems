class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stq;
        for(int size: asteroids){
            if(size > 0){
                stq.push(size);
            } else{
                while(!stq.empty() && stq.top() > 0 && stq.top() < -size ){
                    stq.pop();
                }
                if(stq.empty() || stq.top() < 0) stq.push(size);
                if(!stq.empty() && stq.top() == -size) stq.pop();
            }
        }
        int i = stq.size();
        vector<int> result(i);
        while(!stq.empty()) {
            result[--i] = stq.top();
            stq.pop();
        }
        return result;
    }
};
