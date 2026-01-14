#include <bits/stdc++.h>
using namespace std;

void printerOne(int ind, int s, int sum, int arr[], int n, int &count)
{
    // If sum already exceeded → prune
    //if(s > sum) return;

    // Base case
    if(ind == n)
    {
        if(s == sum) count++;  // ✅ count here
        return;
    }

    // Include current element
    printerOne(ind + 1, s + arr[ind], sum, arr, n, count);

    // Exclude current element
    printerOne(ind + 1, s, sum, arr, n, count);
}

int main()
{
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    int count = 0;

    printerOne(0, 0, sum, arr, n, count);
    cout << count;
}
