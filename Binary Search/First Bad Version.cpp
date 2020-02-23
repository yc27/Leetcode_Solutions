/*
    Runtime: 0 ms
    Memory Usage: 8.2 MB
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n, m;
        
        while(l <= r)
        {
            m = l + (r - l) / 2;
            
            if(isBadVersion(m) == true)
                r = m - 1;
            else
                l = m + 1;
        }
        
        return l;
    }
};
