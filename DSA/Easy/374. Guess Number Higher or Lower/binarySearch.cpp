/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        while(i <= n) {
            int pick = i + (n - i) / 2;
            int guessed = guess(pick);
            if(guessed == 0) return pick;
            else if (guessed < 0) n = pick - 1;
            else i = pick + 1;
        }
        return -1;
    }
};
