/*
    Runtime: 172 ms
    Memory Usage: 14.2 MB
*/

class Solution {
public:
    int numSquares(int n) {
	    vector<unsigned long long> vec, dp(n+5, INT_MAX);
        for(unsigned long long i = 1; i*i <= n; ++i)
            vec.push_back(i*i);
        
        dp[0] = 0;
        for(unsigned long long i = 0; i <= n; ++i)
            for(unsigned long long j = 0; j < vec.size(); ++j)
                if(i >= vec[j])
                    dp[i] = min(dp[i], dp[ i-vec[j] ]+1);
                
        return dp[n];
    }
};