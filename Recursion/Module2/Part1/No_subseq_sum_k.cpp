#include <bits/stdc++.h>
using namespace std;

int printerOne(int ind, int s, int sum, int arr[], int n)
{
    if(s > sum) return 0;
    if (ind == n)
    {
        if (s == sum)
        {
            return 1;
        }
        return 0;
    }

    s += arr[ind];

    int l = printerOne(ind + 1, s, sum, arr, n);

    s -= arr[ind];

    int r = printerOne(ind + 1, s, sum, arr, n);

    return l + r;
}

int main()
{
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    // vector<int> ds;
    cout << printerOne(0, 0, sum, arr, n);
}


void printOn(int index , int s , int sum , int arr[] , int n){
    if(index == n){
        if(sum == s){
            
        }
    }
}