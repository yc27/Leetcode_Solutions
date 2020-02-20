/*
    Runtime: 4 ms
    Memory Usage: 8.4 MB
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 0, h = n, m, g;
        
        while(l <= h) {
            m = l + (h-l) / 2;
            g = guess(m);
            
            if(g == 0)
                return m;
            
            if(g == 1)
                l = m + 1;
            else
                h = m -1;
        }
        return h;
    }
};
