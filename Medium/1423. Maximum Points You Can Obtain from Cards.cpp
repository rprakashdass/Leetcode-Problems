// Sliding window O(2*K)

class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        int sum = 0;

        for(int i = 0;i < k;i++){
            sum += card[i];
        }

        int maxSum = sum;
        int left_ptr = k-1;

        for(int i = n-1;i >= n-k;i--){
            sum -= card[left_ptr];
            left_ptr--;
            sum += card[i];
            maxSum = max(maxSum, sum);
        }

        return maxSum;

    }

// 
};
