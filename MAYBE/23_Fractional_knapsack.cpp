#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> values(n), weights(n);
    for (int i = 0; i < n; i++) cin >> values[i];
    for (int i = 0; i < n; i++) cin >> weights[i];

    int W;
    cin >> W;

    // pair = {value/weight, index}
    vector<pair<double, int>> ratio;
    for (int i = 0; i < n; i++) {
        ratio.push_back({(double)values[i] / weights[i], i});
    }

    // sort by ratio descending
    sort(ratio.begin(), ratio.end(), greater<>());

    double maxValue = 0.0;

    for (auto &p : ratio) {
        int i = p.second;

        if (W == 0) break;

        if (weights[i] <= W) {
            W -= weights[i];
            maxValue += values[i];
        } else {
            maxValue += p.first * W;
            W = 0;
        }
    }

    cout << fixed << setprecision(2) << maxValue;
    return 0;
}
