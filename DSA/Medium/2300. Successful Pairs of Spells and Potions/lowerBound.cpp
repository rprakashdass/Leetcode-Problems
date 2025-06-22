class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> result;
        sort(potions.begin(), potions.end());
        int potionLen = potions.size();
        for(int spell: spells) {
            // spell * potion >= success -> portion >= succss / spell 
            // equivalent to (success / spell)
            long long minPotion = (success + spell - 1) / spell;
            int index = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            result.push_back(potionLen - index);
        }
        return result;
    }
};
