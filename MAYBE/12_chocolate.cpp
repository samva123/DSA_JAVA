#include <bits/stdc++.h>
using namespace std;

int maxChocoUtil(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) {
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;
    if (i == n - 1) {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = INT_MIN;
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            int ans;
            if (j1 == j2)
                ans = grid[i][j1] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            else
                ans = grid[i][j1] + grid[i][j2] + maxChocoUtil(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int maximumChocolatesMemo(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return maxChocoUtil(0, 0, m - 1, n, m, grid, dp);
}













int maximumChocolatesTabu(int n, int m, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9;
                        else
                            ans += dp[i + 1][j1 + di][j2 + dj];
                        maxi = max(ans, maxi);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}






















int maximumChocolatesSpaceOpt(int n, int m, vector<vector<int>> &grid) {
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> cur(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                front[j1][j2] = grid[n - 1][j1];
            else
                front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = INT_MIN;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ans;
                        if (j1 == j2)
                            ans = grid[i][j1];
                        else
                            ans = grid[i][j1] + grid[i][j2];
                        if ((j1 + di < 0 || j1 + di >= m) || (j2 + dj < 0 || j2 + dj >= m))
                            ans += -1e9;
                        else
                            ans += front[j1 + di][j2 + dj];
                        maxi = max(ans, maxi);
                    }
                }
                cur[j1][j2] = maxi;
            }
        }
        front = cur;
    }
    return front[0][m - 1];
}

int main() {
    vector<vector<int>> matrix{
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Recursive + Memoization: " << maximumChocolatesMemo(n, m, matrix) << endl;
    cout << "Tabulation: " << maximumChocolatesTabu(n, m, matrix) << endl;
    cout << "Space Optimized: " << maximumChocolatesSpaceOpt(n, m, matrix) << endl;

    return 0;
}


//////////////////////////best time on leetcode ////////////
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m  = grid[0].size();
        vector<vector<int>> front(m, vector<int>(m, 0));
        vector<vector<int>> cur(m, vector<int>(m, 0));

        // Last row
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                if (j1 == j2)
                    front[j1][j2] = grid[n - 1][j1];
                else
                    front[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        // Remaining rows
        for (int i = n - 2; i >= 0; i--) {

            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {

                    int chocolates;

                    if (j1 == j2)
                        chocolates = grid[i][j1];
                    else
                        chocolates = grid[i][j1] + grid[i][j2];

                    int best = -1e9;

                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {

                            int nj1 = j1 + di;
                            int nj2 = j2 + dj;

                            if (nj1 < 0 || nj1 >= m ||
                                nj2 < 0 || nj2 >= m)
                                continue;

                            best = max(best,
                                    chocolates + front[nj1][nj2]);
                        }
                    }

                    cur[j1][j2] = best;
                }
            }

            swap(front, cur);
        }

        return front[0][m - 1];
    }
};