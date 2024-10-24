// Bruite Force (Time limit exceeded) - O(n*n*n)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0;i < n;i++){
            for(int j = i;j < n;j++){
                int c = i;
                int prod = 1;
                while(c <= j){
                    prod *= nums[c];
                    c++;
                }
                if(prod < k){
                    count++;
                } else{
                    break;
                }
            }
        }

        return count;
    }
};

// Time limit exeeded - O(N*N)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i = 0;i < n;i++){
            int prod = 1;
            for(int j = i;j < n;j++){
                prod *= nums[j];
                if(prod >= k) break;
                else{
                    cout << prod << " ";
                    count++;
                } 
            }
            
        }

        return count;
    }

//
