#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>arr){
    int count  = 0 ;
    if(arr.size() == 1){
        return 0;
    }
    for(auto i : arr){
        if(i%2 == 0){
            continue;
        }else{
            count++;
        }
    }
    return count+1;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int n ;
        cin >> n ;
        
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++){
            cin >> arr[i];
        }
        cout << solve(arr);
    }
}