/*
    Runtime: 4 ms
    Memory Usage: 8.6 MB
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
            return -1;
        
        int l = 0, h = nums.size() - 1, m;
        while(l < h) {
            m = l + (h - l) / 2;
            
            if(nums[m] > nums[m+1])
                h = m;
            else
                l = m + 1;
        }
        return h;
    }
};
