#include <bits/stdc++.h>
using namespace std;

// 1. Memoization (Top-Down)
int solveMemo(int ind, vector<int>& height, vector<int>& dp) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int jumpOne = solveMemo(ind - 1, height, dp) + abs(height[ind] - height[ind - 1]);
    int jumpTwo = INT_MAX;
    if (ind > 1)
        jumpTwo = solveMemo(ind - 2, height, dp) + abs(height[ind] - height[ind - 2]);

    return dp[ind] = min(jumpOne, jumpTwo);
}

// 2. Tabulation (Bottom-Up)
int solveTabulation(vector<int>& height) {
    int n = height.size();
    vector<int> dp(n, 0);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
        int jumpTwo = INT_MAX;
        if (i > 1)
            jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(jumpOne, jumpTwo);
    }

    return dp[n - 1];
}

// 3. Space Optimization
int solveSpaceOptimized(vector<int>& height) {
    int n = height.size();
    int prev = 0, prev2 = 0;

    for (int i = 1; i < n; i++) {
        int jumpOne = prev + abs(height[i] - height[i - 1]);
        int jumpTwo = INT_MAX;
        if (i > 1)
            jumpTwo = prev2 + abs(height[i] - height[i - 2]);

        int cur_i = min(jumpOne, jumpTwo);
        prev2 = prev;
        prev = cur_i;
    }

    return prev;
}

int main() {
    vector<int> height{30, 10, 60, 10, 60, 50};
    int n = height.size();

    // 1. Memoization
    vector<int> dp(n, -1);
    cout << "Memoization Result: " << solveMemo(n - 1, height, dp) << endl;

    // 2. Tabulation
    cout << "Tabulation Result: " << solveTabulation(height) << endl;

    // 3. Space Optimized
    cout << "Space Optimized Result: " << solveSpaceOptimized(height) << endl;

    return 0;
}
