#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int help(int i , int j , bool isTrue , string value){
    if(i > j) return 0;
    if(i == j ){
        if(isTrue ==  1) return value[i] == 'T';
        else return value[i] == 'F';
    }

    int ways  = 0 ;
    for(int k  = i+1 ; k < j ; k+=2  ){
        int lT = help(i , k-1 , 1 , value);
        int lF = help(i , k-1 , 0 , value);
        int rT = help(k+1 , j , 1 , value);
        int rF  =help(k+1 , j , 0 , value);


        if (value[k] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (value[k] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways%mod;

}

int main(){
    string value = "T|F^T";
    int n  = value.size();
    cout << help(0 , n-1 , 1 ,  value);
}