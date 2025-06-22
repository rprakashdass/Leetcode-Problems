class Solution {
public:
    int binarySearch(vector<int>& potions, int spell, long long success) {
        int left  = 0, right = potions.size()-1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if((long long) potions[mid] * spell >= success) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end());
        int potionLen = potions.size();
        for(int spell: spells) {
            int index = binarySearch(potions, spell, success);
            result.push_back(potionLen - index);
        }
        return result;
    }
};
