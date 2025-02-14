class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftBlock(n), rightBlock(n);
        leftBlock[0] = height[0];
        rightBlock[n-1] = height[n-1];
        int trappedWater = 0;
        for(int i = 1;i < n;i++){
            leftBlock[i] = max(leftBlock[i-1], height[i]);
            rightBlock[n-i-1] = max(rightBlock[n-i], height[n-i-1]);
        }
        for(int i = 0;i < n;i++){
            trappedWater += (min(leftBlock[i], rightBlock[i]) - height[i]);
        }
        return trappedWater;
    }
};
