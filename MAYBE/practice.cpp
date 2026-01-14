#include <bits/stdc++.h>
using namespace std;

vector<string> generateCases(string s) {
    vector<string> ans;
    ans.push_back(s);
    int n = s.size();

    for(int i = 0; i < n; i++) {
        if(isdigit(s[i])) continue;

        int currSize = ans.size();

        for(int j = 0; j < currSize; j++) {
            string temp = ans[j];
            temp[i] = islower(temp[i]) ? toupper(temp[i]) : tolower(temp[i]);
            ans.push_back(temp);
        }
    }

    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> res = generateCases(s);
    for(auto &x : res) cout << x << " ";
    return 0;
}
