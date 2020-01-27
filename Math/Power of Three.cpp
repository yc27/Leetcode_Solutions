/*
    Runtime: 12 ms
    Memory Usage: 8 MB
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1)
            return true;
        if(n < 3)
            return false;
        
        while(n > 3) {
            if(n%3)
                return false;
            n /= 3;
        }
        return n%3 == 0;
    }
};