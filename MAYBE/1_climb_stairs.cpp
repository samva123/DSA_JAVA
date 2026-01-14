#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 1. Recursive Solution
    int recursive(int n) {
        if (n == 0 || n == 1) return 1;
        return recursive(n - 1) + recursive(n - 2);
    }

    // 2. Memoization (Top-Down DP)
    int memoizationHelper(int n, vector<int>& dp) {
        if (n == 0 || n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        return dp[n] = memoizationHelper(n - 1, dp) + memoizationHelper(n - 2, dp);
    }

    int memoization(int n) {
        vector<int> dp(n + 1, -1);
        return memoizationHelper(n, dp);
    }

    // 3. Tabulation (Bottom-Up DP)
    int tabulation(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n + 1, -1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // 4. Space Optimization
    int spaceOptimized(int n) {
        if (n == 0 || n == 1) return 1;
        int prev2 = 1, prev = 1, cur;
        for (int i = 2; i <= n; ++i) {
            cur = prev + prev2;
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};

int main() {
    Solution sol;
    int n = 5;

    cout << "Climb Stairs using Recursive: " << sol.recursive(n) << endl;
    cout << "Climb Stairs using Memoization: " << sol.memoization(n) << endl;
    cout << "Climb Stairs using Tabulation: " << sol.tabulation(n) << endl;
    cout << "Climb Stairs using Space Optimization: " << sol.spaceOptimized(n) << endl;

    return 0;
}
