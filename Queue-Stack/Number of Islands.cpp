/*
    Runtime: 12 ms
    Memory Usage: 11 MB
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        
        int islands = 0;
        int m = grid.size(), n = grid[0].size(), x, y, ux, uy;
        bool visit[m][n];        
        queue<pair<int,int> > q;
        
        memset(visit, 0, sizeof visit);
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1' && !visit[i][j])
                {
                    ++islands;
                    q.push({i, j});
                    while(!q.empty())
                    {
                        ux = q.front().first;
                        uy = q.front().second;
                        q.pop();
                        
                        for(int k = 0; k < 4; ++k)
                        {
                            x = ux + dx[k];
                            y = uy + dy[k];
                            if(x>=0 && x<m && y>=0 && y<n)
                            {
                                if(grid[x][y] == '1' && !visit[x][y])
                                {
                                    visit[x][y] = 1;
                                    q.push({x, y});
                                }
                            }
                        }
                    }
                }
            }
        }
        
        return islands;
    }
};