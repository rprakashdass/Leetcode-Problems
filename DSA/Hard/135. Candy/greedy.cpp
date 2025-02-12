class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        candies[0] = 1;
        for(int i = 1;i < n;i++){
            if(ratings[i-1] < ratings[i]) candies[i] = candies[i-1] + 1;
        }
        int candiesRequiered = candies[n-1];
        for(int i = n-2;i >= 0;i--){
            if(ratings[i] > ratings[i + 1] && candies[i] <= candies[i+1]) {
                candies[i] = candies[i+1] + 1;
            }
            candiesRequiered += candies[i];
        }
        return candiesRequiered;
    }
}; 
