#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int help(int i , int j  , vector<vector<int>>& matrix ,vector<vector<int>>&dp ){
        if(i == 0  && j == 0 ){
            return matrix[0][0];
        }
        if(i < 0  || j < 0){
            return INT_MAX;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int up = INT_MAX, left = INT_MAX;
        // we can initalise them with 0 but then we have to else condition at time of calling like 
        // tabulation approach mean adding int_max in case if i or j is less than or equal to 0 

        if (j > 0)
            up = matrix[i][j] + help(i, j - 1, matrix, dp);
        if (i > 0)
            left = matrix[i][j] + help(i - 1, j, matrix, dp);
        return dp[i][j] = min(up , left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();
        vector<vector<int>>dp(n , vector<int>(m , -1));

        return help(n-1 , m-1 , grid , dp);
        
    }
};











// and one more thing we have to do += when we initalise them with matrix[i][j]
// if we initailse them with 0 and add matrix[i][j] at time of call then only = is enough 



///////////if we use 1e9 instead of int_max

class Solution {
public:
    int help(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {

        if (i == 0 && j == 0)
            return grid[0][0];

        if (i < 0 || j < 0)
            return 1e9;      // safe large value, no overflow

        if (dp[i][j] != -1)
            return dp[i][j];

        int up   = grid[i][j] + help(i - 1, j, grid, dp);
        int left = grid[i][j] + help(i, j - 1, grid, dp);

        return dp[i][j] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return help(n - 1, m - 1, grid, dp);
    }
};


















#include <bits/stdc++.h>
using namespace std;

int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                dp[i][j] = matrix[i][j];
            else {
                int up = matrix[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;

                int left = matrix[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;

                dp[i][j] = min(up, left);
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}


// int minSumPath(int n, int m, vector<vector<int>> &matrix) {
//         vector<vector<int>> dp(n, vector<int>(m, 0));

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (i == 0 && j == 0)
//                     dp[i][j] = matrix[i][j];
//                 else {
//                     //int up = matrix[i][j];
//                     int up = 0 ;
//                     int left  = 0 ;
//                     if (i > 0)
//                          up = matrix[i][j] +  dp[i - 1][j];
//                     else
//                          up = matrix[i][j] + 1e9;

//                     //int left = matrix[i][j];
//                     if (j > 0)
//                          left = matrix[i][j] + dp[i][j - 1];
//                     else
//                          left = matrix[i][j] +1e9;

//                     dp[i][j] = min(up, left);
//                 }
//             }
//         }

//         return dp[n - 1][m - 1];
//     }


































#include <bits/stdc++.h>
using namespace std;

int minSumPath(int n, int m, vector<vector<int>> &matrix) {
    vector<int> prev(m, 0);

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                temp[j] = matrix[i][j];
            else {
                int up = matrix[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;

                int left = matrix[i][j];
                if (j > 0)
                    left += temp[j - 1];
                else
                    left += 1e9;

                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }

    return prev[m - 1];
}

int main() {
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    cout << "Minimum sum path: " << minSumPath(n, m, matrix) << endl;
    return 0;
}














