// Brute Force Solution

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector< int > result;
        vector<int> pos;
        vector<int> neg;

        int n = nums.size();

        for(int i = 0;i < n;i++){
            if(nums[i] > 0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }

        int k = 0,j = 0;
        for(int i = 0;i < n;i++){
            if(i % 2 == 0){
                result.push_back(pos[k]);
                k++;
            }
            else{
                result.push_back(neg[j]);
                j++;
            }
        }

        return result;

    }
};

// Optimized Approach

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int posIndex = 0;
        int negIndex = 1;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                result[posIndex] = nums[i];
                posIndex += 2;
            } else {
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return result;
    }
};
