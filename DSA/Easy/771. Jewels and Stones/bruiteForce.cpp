class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(auto a: jewels){
            for(auto b: stones){
                count += (a==b);
            }
        }
        return count;
    }
};
