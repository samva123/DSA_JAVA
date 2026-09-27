#include <bits/stdc++.h>
using namespace std;


// ============================================================
// 1. MEMOIZATION
// ============================================================

int solveMemo(int i, int j,
              vector<vector<int>>& matrix,
              vector<vector<int>>& dp) {

    if (i < 0 || j < 0)
        return 0;

    if (matrix[i][j] == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    return dp[i][j] = 1 + min({
        solveMemo(i - 1, j, matrix, dp),
        solveMemo(i, j - 1, matrix, dp),
        solveMemo(i - 1, j - 1, matrix, dp)
    });
}

int countSquaresMemo(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(
        n,
        vector<int>(m, -1)
    );

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += solveMemo(i, j, matrix, dp);
        }
    }

    return ans;
}


// ============================================================
// 2. TABULATION
// ============================================================

int countSquaresTabulation(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(
        n,
        vector<int>(m, 0)
    );

    int ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (matrix[i][j] == 0) {

                dp[i][j] = 0;

            }
            else if (i == 0 || j == 0) {

                dp[i][j] = 1;

            }
            else {

                dp[i][j] = 1 + min({
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                });
            }

            ans += dp[i][j];
        }
    }

    return ans;
}


// ============================================================
// 3. SPACE OPTIMIZATION
// ============================================================

int countSquaresSpaceOptimized(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> prev(m, 0);
    vector<int> cur(m, 0);

    int ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (matrix[i][j] == 0) {

                cur[j] = 0;

            }
            else if (i == 0 || j == 0) {

                cur[j] = 1;

            }
            else {

                cur[j] = 1 + min({
                    prev[j],
                    cur[j - 1],
                    prev[j - 1]
                });
            }

            ans += cur[j];
        }

        prev = cur;
    }

    return ans;
}


// ============================================================
// MAIN
// ============================================================

int main() {

    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };

    cout << "Memoization: "
         << countSquaresMemo(matrix)
         << endl;

    cout << "Tabulation: "
         << countSquaresTabulation(matrix)
         << endl;

    cout << "Space Optimized: "
         << countSquaresSpaceOptimized(matrix)
         << endl;

    return 0;
}