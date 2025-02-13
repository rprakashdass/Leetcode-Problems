class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n, 1), backward(n, 1), result(n, 1);

        forward[0] = nums[0];
        for(int i = 1;i < n;i++){
            forward[i] = forward[i-1] * nums[i];
        }

        backward[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;i--){
            backward[i] = backward[i+1] * nums[i];
        }

        result[0] = backward[1], result[n-1] = forward[n-2];
        for(int i = 1;i < n-1;i++){
            result[i] = forward[i-1] * backward[i+1];
        }
        return result;
    }
};
