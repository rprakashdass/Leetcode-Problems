class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minCount = INT_MAX;
        for(int i = 0;i+k <= n;i++){
            int count = 0;
                for(int j = i;j < i+k;j++){
                    if(blocks[j] == 'W'){
                        count++;
                    }
                }
            minCount = min(minCount, count);
        }
        return minCount;
    }
};
