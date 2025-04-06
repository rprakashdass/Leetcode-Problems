class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        bool flag = true;
        int x = 0, y = 0, count = 0;
        while(flag && nums.size() >= 2){
            int order = 0;
            pair<int, int> min_pair = make_pair(-1, -1);
            for(int i = nums.size()-1;i > 0;i--){
                if(nums[i] >= nums[i-1]){
                    order++;
                }
                if(min_pair.first != -1){
                    x = nums[i-1];
                    y = nums[i];
                    int sum = nums[min_pair.first] + nums[min_pair.second];
                    if(sum >= x+y){
                        min_pair = make_pair(i-1, i);
                    }
                } else {
                    min_pair = make_pair(i-1, i);
                }
            }
            if(order == nums.size()-1) break;
            if(flag){
                nums[min_pair.first] = nums[min_pair.first] + nums[min_pair.second];
                nums.erase(nums.begin() + min_pair.second);
            }
            count++;
        }
        return count;
    }
};
