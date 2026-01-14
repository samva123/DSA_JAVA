#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 1. Pure Recursion
    int f(int ind, int N, vector<int>& price) {
        if (ind == 0) {
            return N * price[0];
        }

        int notTake = f(ind - 1, N, price);
        int take = INT_MIN;

        int rodLength = ind + 1;
        if (rodLength <= N) {
            take = price[ind] + f(ind, N - rodLength, price);
        }
        return max(take, notTake);
    }

    int cutRodRecursion(vector<int>& price) {
        int n = price.size();
        return f(n - 1, n, price);
    }


    // 2. Memoization
    int m(int ind, int N, vector<int>& price, vector<vector<int>>& dp) {
        if (ind == 0) {
            return N * price[0];
        }
        if (dp[ind][N] != -1) return dp[ind][N];

        int notTake = m(ind - 1, N, price, dp);
        int take = INT_MIN;

        int rodLength = ind + 1;
        if (rodLength <= N) {
            take = price[ind] + m(ind, N - rodLength, price, dp);
        }
        return dp[ind][N] = max(take, notTake);
    }

    int cutRodMemoization(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return m(n - 1, n, price, dp);
    }


    // 3. Tabulation
    int cutRodTabulation(vector<int>& price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int N = 0; N <= n; N++) {
            dp[0][N] = N * price[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int N = 1; N <= n; N++) {
                int notTake = dp[ind - 1][N];
                int take = INT_MIN;

                int rodLength = ind + 1;
                if (rodLength <= N) {
                    take = price[ind] + dp[ind][N - rodLength];
                }
                dp[ind][N] = max(take, notTake);
            }
        }
        return dp[n - 1][n];
    }


    // 4. Space Optimized Tabulation
    int cutRodSpaceOptimized(vector<int>& price) {
        int n = price.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int N = 0; N <= n; N++) {
            prev[N] = N * price[0];
        }

        for (int ind = 1; ind < n; ind++) {
            for (int N = 1; N <= n; N++) {
                int notTake = prev[N];
                int take = INT_MIN;

                int rodLength = ind + 1;
                if (rodLength <= N) {
                    take = price[ind] + cur[N - rodLength];
                }
                cur[N] = max(take, notTake);
            }
            prev = cur;
        }
        return prev[n];
    }
};


// Driver
int main() {
    Solution sol;
    vector<int> price = {2, 5, 7, 8, 10};  // example price array

    cout << "Recursion: " << sol.cutRodRecursion(price) << endl;
    cout << "Memoization: " << sol.cutRodMemoization(price) << endl;
    cout << "Tabulation: " << sol.cutRodTabulation(price) << endl;
    cout << "Space Optimized: " << sol.cutRodSpaceOptimized(price) << endl;

    return 0;
}
