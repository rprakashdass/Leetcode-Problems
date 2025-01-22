class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        for(auto a: jewels){
            cnt += count(stones.begin(), stones.end(), a);
        }
        return cnt;
    }
};
