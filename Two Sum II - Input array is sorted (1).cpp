/*
	Runtime: 4 ms
	Memory Usage: 9.5 MB
*/

class Solution {
public:    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int h = numbers.size() - 1;
        while(numbers[l] + numbers[h] != target) {
            if(numbers[l] + numbers[h] < target) 
                l ++;
            else
                h --;
        }
        return {l + 1, h + 1};
    }
};