#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

int kDistinctChars(int k, string &s)
{
    // Write your code here
    int n  = s.size();
    int maxlen  = 0 ;
    unordered_map<char , int>mpp;

    for(int  i = 0 ; i < n ; i++){
        mpp.clear();
        for(int j = i ; j < n ; j++){
            mpp[s[j]]++;
            if(mpp.size() <= k){
                maxlen  = max(maxlen , j-i+1);
            }else{
                break;
            }
        }
    }
    return maxlen;


}


#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    int left = 0, maxlen = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < str.size(); right++) {
        freq[str[right]]++;  // Expand window

        while (freq.size() > k) {  // Shrink window if more than `k` unique characters
            freq[str[left]]--;
            if (freq[str[left]] == 0) {
                freq.erase(str[left]);
            }
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
}






#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    int left = 0, maxlen = 0;
    unordered_map<char, int> freq;

    for (int right = 0; right < str.size(); right++) {
        freq[str[right]]++;  // Expand window

        if(freq.size() > k) {  // Shrink window if more than `k` unique characters
            freq[str[left]]--;
            if (freq[str[left]] == 0) {
                freq.erase(str[left]);
            }
            left++;
        }

        maxlen = max(maxlen, right - left + 1);
    }

    return maxlen;
}
