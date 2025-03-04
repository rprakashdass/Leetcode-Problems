class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int size = flowerbed.size();
        if(flowerbed[0] == 0){
            if(size > 1 && flowerbed[1] == 0){
                flowerbed[0] = 1, n--;
            } else if(size == 1){
                flowerbed[0] = 1, n--;
                if(n == 0) return true;
            }
        }

        for(int i = 1;i < size-1;i++){
            if(flowerbed[i] == 0){
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }
            if(n == 0) return true;
        }

        if(size > 2 && flowerbed[size-1] == 0 && flowerbed[size-2] == 0){
            flowerbed[size-1] = 1;
            n--;
        }
        return (n == 0) ? true : false;
    }
};
