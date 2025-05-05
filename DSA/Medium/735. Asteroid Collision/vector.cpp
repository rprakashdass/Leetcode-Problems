class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        int i = 0, prevSize = 0;
        bool isCollide = true;
        while(isCollide && !asteroids.empty()){
            result.clear();
            isCollide = false;
            for(int size: asteroids){
                if(!result.empty() && size < 0 && prevSize > 0){
                    if(-size >= prevSize){
                        result.pop_back();
                        if (-size > prevSize){
                            result.push_back(size);
                        }
                        isCollide = true;
                    }
                } else {
                    result.push_back(size);
                }
                if(!result.empty()) prevSize = result.back();
            }
            asteroids = result;
        }
        return result;
    }
};
