class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> elementCount;
        unordered_map<int, int> occuranceCount;
        for(int num: arr){
            int count = elementCount[num];
            if(count > 0){
                occuranceCount[count]--;
            }
            elementCount[num]++;
            occuranceCount[++count]++;
        }
        for(auto [key, value]: occuranceCount){
            if(value > 1) return false;
        }
        return true;
    }
};
