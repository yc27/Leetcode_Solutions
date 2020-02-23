/*
    Runtime: 4 ms
    Memory Usage: 8.8 MB
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, h = nums.size()-1, m;
        
        while(l < h) {
            m = l + (h - l) / 2;
            
            if(nums[m] > nums[h])
                l = m + 1;
            else
                h = m;
        }
        
        return nums[l];
    }
};
