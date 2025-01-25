class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        for(int n: nums){
            if(n == 0) c0++;
            if(n == 1) c1++;
            if(n == 2) c2++;
        }
        for(int i = 0;i < c0;i++) nums[i] = 0;
        for(int i = c0;i < c0+c1;i++) nums[i] = 1;
        for(int i = c0+c1;i < c0+c1+c2;i++) nums[i] = 2;
    }
};
