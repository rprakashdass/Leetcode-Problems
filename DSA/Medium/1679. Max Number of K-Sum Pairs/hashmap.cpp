class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> counter;
        for(int num: nums){
            int needed = k - num;
            if(counter.find(needed) != counter.end() && counter[needed] > 0){
                counter[needed]--;
                count++;
            } else {
                counter[num]++;
            }
        }
        return count;
    }
};
