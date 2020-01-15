/*
    Runtime: 392 ms
    Memory Usage: 31 MB
*/

class Solution {
public:    
    int openLock(vector<string>& deadends, string target) {        
        string str;
        set<string> dead(deadends.begin(), deadends.end()), visit;
        queue<string> q;
        q.push("0000");
        for(int dis = 0; !q.empty(); ++dis)
        {
            for(int n = q.size(); n > 0; --n) {
                str = q.front();
                q.pop();

                if(dead.find(str) != dead.end())
                    continue;

                for(int i = 0; i < 4; ++i)
                {
                    if(str[i] != '9') {
                        str[i] += 1;

                        if(str == target)
                            return dis+1;

                        if(visit.find(str) == visit.end()) {
                            q.push(str);
                            visit.insert(str);
                        }
                        str[i] -= 1;
                    } else {
                        str[i] = '0';

                        if(str == target)
                            return dis+1;

                        if(visit.find(str) == visit.end()) {
                            q.push(str);
                            visit.insert(str);
                        }
                        str[i] = '9';
                    }

                    if(str[i] != '0') {
                        str[i] -= 1;

                        if(str == target)
                            return dis+1;

                        if(visit.find(str) == visit.end()) {
                            q.push(str);
                            visit.insert(str);
                        }
                        str[i] += 1;
                    } else {
                        str[i] = '9';

                        if(str == target)
                            return dis+1;

                        if(visit.find(str) == visit.end()) {
                            q.push(str);
                            visit.insert(str);
                        }
                        str[i] = '0';
                    }
                }
            }
        }
        return -1;
    }
};