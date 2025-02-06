class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2) return n;
        unordered_map<int, int> basket;
        int left = 0, result = 0;
        for(int right = 0;right < n;right++){
            basket[fruits[right]]++;
            if(basket.size() <= 2){
                result = max(result, right-left+1);
            } else {
                basket[fruits[left]]--;
                if(!basket[fruits[left]]) basket.erase(fruits[left]);
                left++;
            }
        }
        return result;
    }
};
