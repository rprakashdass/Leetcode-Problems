class Solution {
public:
    bool canEatAll(vector<int>& piles, int hour, int k) {
        double time = 0;
        for(int pile: piles) {
            time += ceil((double)pile / (double)k);
        }
        return time <= hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canEatAll(piles, h, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
