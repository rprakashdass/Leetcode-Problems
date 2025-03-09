class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int currentAltitude = 0;
        
        for (int change : gain) {
            currentAltitude += change;
            maxAltitude = max(maxAltitude, currentAltitude);
        }
        
        return maxAltitude;
    }
};
