/*
    Runtime: 4 ms
    Memory Usage: 8.8 MB
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1, m;
        
        if(h < 0)
            return -1;
        
        // find rotation point
        while(l < h) {
            m = l + (h - l) / 2;
            
            if(nums[m] > nums[h])
                l = m + 1;
            else
                h = m;
        }
        
        // find the correct search boundary
        h = nums.size()-1;
        if(target > nums[h]) {
            h = l;
            l = 0;
        }
        
        // search in the boundary
        while(l <= h) {
            m = l + (h - l) / 2;
            
            if(target == nums[m])
                return m;
            
            if(target < nums[m])
                h = m - 1;
            else
                l = m + 1;
        }
        
        return -1;
    }
};
