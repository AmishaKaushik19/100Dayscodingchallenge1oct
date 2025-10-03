
// 407.trapping rain water II
/*
solution -


class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;

        int n = heightMap.size();
        int m = heightMap[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    q.push({heightMap[i][j], i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int ans = 0;

        while (!q.empty()) {
            int h = q.top()[0];
            int x = q.top()[1];
            int y = q.top()[2];
            q.pop();

            for (int k = 0; k < 4; k++) {

                int nx = dx[k] + x;
                int ny = dy[k] + y;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] ) {

                    ans += max(h - heightMap[nx][ny],0);
                    q.push({max(h, heightMap[nx][ny]), nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        return ans;
    }
};


*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        if (heightMap.empty() || heightMap[0].empty())
            return 0;

        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    q.push({heightMap[i][j], i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int ans = 0;

        while (!q.empty())
        {
            int h = q.top()[0];
            int x = q.top()[1];
            int y = q.top()[2];
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                {

                    ans += max(h - heightMap[nx][ny], 0);

                    q.push({max(h, heightMap[nx][ny]), nx, ny});

                    vis[nx][ny] = 1;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};
    cout << sol.trapRainWater(heightMap) << endl; // Output: 4
    return 0;
}
