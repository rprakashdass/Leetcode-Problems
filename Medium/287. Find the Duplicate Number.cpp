// Bruite Force Approach

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> hashMap;
        for( int num : nums ) {
            if( hashMap.find(num) != hashMap.end()) {
                hashMap[num]++;
            } else {
                hashMap[num] = 1;
            }
        }
        for(auto it = hashMap.begin();it != hashMap.end();it++){
            if (it->second > 1) return it->first;
        }
        return 0;
    }
};
