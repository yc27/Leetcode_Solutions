/*
    Runtime: 8 ms
    Memory Usage: 10.3 MB
*/

class Solution {
public:
    int findIndex(vector<int>& nums, int target, bool left) {
        int l = 0, h = nums.size(), m;
        
        while(l < h) {
            m = l + (h - l) / 2;
            
            if(nums[m] > target || (left && nums[m] == target))
                h = m;
            else
                l = m + 1;
        }
        
        return l;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        
        int x, y;
        
        x = findIndex(nums, target, true);
        
        if(x == nums.size() || nums[x] != target)
            return {-1, -1};
        
        y = findIndex(nums, target, false) - 1;
        
        return {x, y};
    }
};
