class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n-1];
        int left = 0, right = n-1;
        int trappedWater = 0;
        while(left < right){
            if(height[left] < height[right]){
                left++;
                leftMax = max(leftMax, height[left]);
                trappedWater += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                trappedWater += rightMax - height[right];
            }
        }

        return trappedWater;
    }
};
