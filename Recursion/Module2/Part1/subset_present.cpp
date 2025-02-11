#include <bits/stdc++.h>
using namespace std;




bool helper(int index, vector<int> &a, int k, int n, int s) {
    if (index >= n) {
        return s == k;  // Return true if subset sum matches k
    }

    // Include current element
    if (helper(index + 1, a, k, n, s + a[index])) {
        return true;
    }

    // Exclude current element
    if (helper(index + 1, a, k, n, s)) {
        return true;
    }

    return false;  // If neither inclusion nor exclusion leads to a solution
}

bool isSubsetPresent(int n, int k, vector<int> &a) {
    return helper(0, a, k, n, 0);
}
