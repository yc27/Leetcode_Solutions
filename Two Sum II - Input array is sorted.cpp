/*
	Runtime: 8 ms
	Memory Usage: 9.6 MB
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l, h, m, n = numbers.size();
        vector<int> v;
        for(int i = 0; i < n; ++i) {
            l = i+1, h = n-1;
            while(l <= h) {
                m = (l+h) / 2;

                if(numbers[m]+numbers[i] == target) {
                    v.emplace_back(i+1);
                    v.emplace_back(m+1);
                    return v;
                }
                
                else if(numbers[m]+numbers[i] > target)
                    h = m-1;
                
                else
                    l = m+1;
            }
        }
        return v;
    }
};