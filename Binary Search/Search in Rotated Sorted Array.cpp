/*
    Runtime: 4 ms
    Memory Usage: 8.8 MB
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        
        int l = 0, h = nums.size()-1, m;
        
        while(l <= h) {
            m = l + (h - l) / 2;
            
            if(nums[m] == target)
                return m;
            
            if(nums[l] <= nums[m]) {
                if(nums[l] <= target && target < nums[m])
                    h = m - 1;
                else
                    l = m + 1;
            }
            
            else {
                if(target > nums[m] && target <= nums[h])
                    l = m + 1;
                else
                    h = m - 1;
            }
        }
        
        return -1;
    }
};
