#include <bits/stdc++.h>
using namespace std;

void printer(int ind , vector<int>&ds , int arr[] , int n){
    if(ind == n){
        for(auto it : ds){
            cout << it << " ";
        }
        if(ds.size() == 0){
            cout << "{}";
        }
        cout << endl;
        return;
    }
    // ds.push_back(arr[ind]);
    // printer(ind+1 , ds , arr , n);
    // ds.pop_back();
    // printer(ind+1 , ds , arr , n);

    printer(ind+1 , ds , arr , n);
    ds.push_back(arr[ind]);
    printer(ind+1 , ds , arr , n);
    ds.pop_back();
    

}


int main(){
    int arr[] = {3,1,2};
    int n  = 3;
    vector<int>ds;
    printer(0 , ds , arr , n);
}

// time is (2^n)*n we multiplied with n due to
// for loop storing result

// space is n