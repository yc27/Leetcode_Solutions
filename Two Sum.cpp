/*
	Runtime: 12 ms
	Memory Usage: 10.5 MB
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> v;
        
        for(int i = 0; i < nums.size(); ++i) {
            if(mp.find( target-nums[i] ) != mp.end()) {
                v.push_back( i );
                v.push_back( mp.find(target-nums[i])->second );
            }
            mp[ nums[i] ] = i;
        }
        return v;
    }
};