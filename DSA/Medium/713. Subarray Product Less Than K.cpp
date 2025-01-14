// Time complexity - O(N)
// Space complexity - O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int n = nums.size();
        int left = 0, right = 0;
        int prod = 1, count = 0;
        while(right < n){
            prod *= nums[right];
            while(prod >= k && left <= right){
                prod /= nums[left++];
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }
};
