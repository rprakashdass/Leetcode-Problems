class Solution {
public:
    //  => stay there at common (left) & move only right
    //  => swap when non-common & move left & right
    int removeDuplicates(vector<int>& nums) {
        int left = 0, k = 1;
        for(int right = 0;right < nums.size();right++){
            if(nums[left] != nums[right]){
                swap(nums[++left], nums[right]);
                k++;
            }
        }
        return k;
    }
};
