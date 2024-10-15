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
