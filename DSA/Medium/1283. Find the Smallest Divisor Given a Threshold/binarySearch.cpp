class Solution {
public:
    bool isSmallest(vector<int>& nums, int threshold, int divisor) {
        double sum = 0;
        for(int num: nums) {
            sum += ceil(double(num) / (double)divisor);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 0, high = *max_element(nums.begin(), nums.end());
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isSmallest(nums, threshold, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
