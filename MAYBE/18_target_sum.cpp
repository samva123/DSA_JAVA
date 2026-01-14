#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e9 + 7;

// ======================== 1. Memoization ========================
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (ind == 0) {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || target == arr[0])
            return 1;
        return 0;
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (notTaken + taken) % mod;
}

int targetSumMemo(int n, int target, vector<int>& arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;

    int s2 = (totSum - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return countPartitionsUtil(n - 1, s2, arr, dp);
}

// ======================== 2. Tabulation ========================
int findWaysTabu(vector<int> &num, int tar) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));

    if (num[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        dp[0][num[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= tar; target++) {
            int notTaken = dp[ind - 1][target];
            int taken = 0;
            if (num[ind] <= target)
                taken = dp[ind - 1][target - num[ind]];
            dp[ind][target] = (notTaken + taken) % mod;
        }
    }

    return dp[n - 1][tar];
}

int targetSumTabu(int n, int target, vector<int>& arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;

    return findWaysTabu(arr, (totSum - target) / 2);
}

// ======================== 3. Space Optimized ========================
int findWaysSpace(vector<int> &num, int tar) {
    int n = num.size();
    vector<int> prev(tar + 1, 0);

    if (num[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if (num[0] != 0 && num[0] <= tar)
        prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        vector<int> cur(tar + 1, 0);
        for (int target = 0; target <= tar; target++) {
            int notTaken = prev[target];
            int taken = 0;
            if (num[ind] <= target)
                taken = prev[target - num[ind]];
            cur[target] = (notTaken + taken) % mod;
        }
        prev = cur;
    }

    return prev[tar];
}

int targetSumSpaceOpt(int n, int target, vector<int>& arr) {
    int totSum = accumulate(arr.begin(), arr.end(), 0);

    if (totSum - target < 0 || (totSum - target) % 2 != 0)
        return 0;

    return findWaysSpace(arr, (totSum - target) / 2);
}

// ======================== Main ========================
int main() {
    vector<int> arr = {1, 2, 3, 1};
    int target = 3;
    int n = arr.size();

    cout << "Memoization: The number of ways found is " << targetSumMemo(n, target, arr) << endl;
    cout << "Tabulation:  The number of ways found is " << targetSumTabu(n, target, arr) << endl;
    cout << "Space Opt:   The number of subsets found is " << targetSumSpaceOpt(n, target, arr) << endl;

    return 0;
}
