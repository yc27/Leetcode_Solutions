/*
    Runtime: 48 ms
    Memory Usage: 10.9 MB
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return -1;
    }
};
