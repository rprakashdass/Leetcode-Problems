// Better oproach

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ar(n+1, 0);
        for(int i = 0;i < n;i++){
            ar[nums[i]]++;
        }
        for(int i = 1;i <= n;i++)
        {
            if(ar[i] == 0)
                return i;
        }
        return 0;
    }
};

// optimal

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0; 
        for(int i = 0;i < n;i++){
            sum += nums[i];
        }
        int first_n_sum = n * (n + 1) / 2;
        return first_n_sum - sum;
    }
};

// better optimal ( using XOR )

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_n = 0, xor_ar = 0; 
        for(int i = 0;i < n;i++){
            xor_n ^= (i+1);
            xor_ar ^= nums[i];
        }
        return ( xor_n ^ xor_ar );
    }
};


// manual sum

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, availableSum = 0;
        for(int i = 0;i < nums.size();i++){
            availableSum += nums[i];
            sum += (i+1);
        }
        return sum - availableSum;
    }
};
