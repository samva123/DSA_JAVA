#include <bits/stdc++.h>
using namespace std;

// ========== 1. Memoization ==========
bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;

    if (dp[ind][target] != -1) return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

bool canPartitionMemo(int n, vector<int>& arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    if (totSum % 2 == 1) return false;

    int k = totSum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return subsetSumUtil(n - 1, k, arr, dp);
}

// ========== 2. Tabulation (2D DP) ==========
bool canPartitionTabu(int n, vector<int>& arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    if (totSum % 2 == 1) return false;

    int k = totSum / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= k; target++) {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = notTaken || taken;
        }
    }

    return dp[n - 1][k];
}

// ========== 3. Space Optimized (1D DP) ==========
bool canPartitionSpaceOpt(int n, vector<int>& arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);
    if (totSum % 2 == 1) return false;

    int k = totSum / 2;
    vector<bool> prev(k + 1, false);
    prev[0] = true;

    if (arr[0] <= k)
        prev[arr[0]] = true;

    for (int ind = 1; ind < n; ind++) {
        vector<bool> cur(k + 1, false);
        cur[0] = true;
        for (int target = 1; target <= k; target++) {
            bool notTaken = prev[target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = prev[target - arr[ind]];
            cur[target] = notTaken || taken;
        }
        prev = cur;
    }

    return prev[k];
}

// ========== Main ==========
int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();

    cout << "Memoization: ";
    if (canPartitionMemo(n, arr))
        cout << "The Array can be partitioned into two equal subsets\n";
    else
        cout << "The Array cannot be partitioned into two equal subsets\n";

    cout << "Tabulation: ";
    if (canPartitionTabu(n, arr))
        cout << "The Array can be partitioned into two equal subsets\n";
    else
        cout << "The Array cannot be partitioned into two equal subsets\n";

    cout << "Space Optimized: ";
    if (canPartitionSpaceOpt(n, arr))
        cout << "The Array can be partitioned into two equal subsets\n";
    else
        cout << "The Array cannot be partitioned into two equal subsets\n";

    return 0;
}
