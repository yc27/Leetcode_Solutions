/*
    Runtime: 12 ms
    Memory Usage: 9.9 MB
*/

class Solution {
private:
int sieve(int n)
{
    if(n < 3)
        return 0;
    
    bool mask[n+5];
    int primeCnt = 0;
    int lim = sqrt(n+1);
    
    memset(mask, 0, sizeof mask);
    ++primeCnt;

    for(int i = 3; i < n; i += 2)
    {
        if(!mask[i])
        {
            ++primeCnt;
            if(i <= lim)
                for(int j = i*i; j <= n; j += i*2)
                    mask[j] = true;
        }
    }

    return primeCnt;
}
public:
    int countPrimes(int n) {
        return sieve(n);
    }
};