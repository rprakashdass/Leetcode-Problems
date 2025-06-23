class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity){
        int currentLoad = 0, daysCount = 1;
        for(int weight: weights) {
            if(currentLoad + weight > capacity) {
                daysCount++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return daysCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canShip(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
