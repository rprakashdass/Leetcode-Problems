// Brute Force Approach

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hashMap;
        
        for(int i = 0;i < n;i++) {
            hashMap[nums[i]] = 0;
        }

        for(auto it: hashMap){
            if(it.second >= (n/2)){
                return it.first;
            }
        }

        return 0;
    }
};

// Optimal Approach (moorce voting algorithm)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int element = 0, count = 0;
        for(int i = 0;i < n;i++) {
            if(!count){
                element = nums[i];
                count++;
            } else if(element == nums[i]) {
                count++;
            } else if(element != nums[i]) {
                count--;
            }
        }

        return element;
    }
};
