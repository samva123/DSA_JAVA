#include <bits/stdc++.h>
using namespace std;

//
// 1. Recursive + Memoization
//
int solveMemoUtil(int ind, vector<int>& arr, vector<int>& dp) {
    if (ind == 0)
        return arr[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];

    int pick = arr[ind] + solveMemoUtil(ind - 2, arr, dp);
    int nonPick = solveMemoUtil(ind - 1, arr, dp);

    return dp[ind] = max(pick, nonPick);
}

int solveMemo(int n, vector<int>& arr) {
    vector<int> dp(n, -1);
    return solveMemoUtil(n - 1, arr, dp);
}

//
// 2. Tabulation
//
int solveTab(int n, vector<int>& arr) {
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        dp[i] = max(pick, nonPick);
    }

    return dp[n - 1];
}

//
// 3. Space Optimized
//
int solveSpaceOpt(int n, vector<int>& arr) {
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1)
            pick += prev2;
        int nonPick = prev;
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev = cur_i;
    }

    return prev;
}

//
// Main Function
//
int main() {
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();

    cout << "Recursive + Memoization: " << solveMemo(n, arr) << endl;
    cout << "Tabulation: " << solveTab(n, arr) << endl;
    cout << "Space Optimized: " << solveSpaceOpt(n, arr) << endl;

    return 0;
}
