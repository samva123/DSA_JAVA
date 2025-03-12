#include <bits/stdc++.h>
using namespace std;

int func(vector<int> v, int k) {
    unordered_map<int, int> mpp;
    int count = 0;

    for (int i = 0; i < v.size(); i++) {
        int need = k - v[i];

        if (mpp.find(need) != mpp.end()) {
            count += mpp[need];
        }
        
        mpp[v[i]]++;
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int k;
    cin >> k;

    cout << func(v, k) << endl;
    return 0;
}
