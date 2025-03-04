class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size(), maxCandy = 0;
        for(int i = 0;i < n;i++)
            maxCandy = max(maxCandy, candies[i]);

        vector<bool> result(n, false);
        for(int i = 0;i < n;i++){
            if(candies[i] + extraCandies >= maxCandy){
                result[i] = true;
            }
        }
        return result;
    }
};
