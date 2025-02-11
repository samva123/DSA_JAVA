// #include <bits/stdc++.h>
// using namespace std;

// void printer(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
// {
//     if (ind == n)
//     {
//         if (s == sum)
//         {
//             for (auto it : ds)
//             {
//                 cout << it << " "; 
//             }
//             cout << endl;
//         }
//         return;
//     }
//     ds.push_back(arr[ind]);
//     s += arr[ind];

//     printer(ind+1 , ds , s , sum , arr , n);

//     s -= arr[ind];
//     ds.pop_back();

//     printer(ind+1 , ds ,s , sum, arr , n);

   
// }

// int main()
// {
//     int arr[] = {1, 1, 2};
//     int n = 3;
//     int sum = 2;
//     vector<int> ds;
//     printer(0, ds, 0, sum, arr, n);
// }

// time is (2^n)*n we multiplied with n due to
// for loop storing result

// space is n


















// Pattern on avoiding extra recursion and printing only one subseq
#include <bits/stdc++.h>
using namespace std;

bool printerOne(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
            {
                cout << it << " "; 
            }
            cout << endl;
            return true;
        }
        return false;
    }
    ds.push_back(arr[ind]);
    s += arr[ind];

    if(printerOne(ind+1 , ds , s , sum , arr , n) == true){
        return true;
    };

    s -= arr[ind];
    ds.pop_back();

    if(printerOne(ind+1 , ds ,s , sum, arr , n) == true) return true;

    return false;

   
}

int main()
{
    int arr[] = {1, 1, 2};
    int n = 3;
    int sum = 2;
    vector<int> ds;
    printerOne(0, ds, 0, sum, arr, n);
}

// time is (2^n)*n we multiplied with n due to
// for loop storing result

// space is n