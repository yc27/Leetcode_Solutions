/*
    Runtime: 4 ms
    Memory Usage: 8.2 MB
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        if(x < 4)
            return 1;
        
        int low = 0, high = x, mid;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            if(mid == x / mid)
                return mid;
            
            if(mid < x / mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
