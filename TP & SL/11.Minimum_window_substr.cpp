#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        string minWindow(string s, string t) {
            int n  = s.size();
            int m = t.size();
            int minlen  = INT_MAX;
            int start  = -1;
            for(int i = 0 ; i < n ; i++){
                int hash[256] = {0};
                int count  = 0 ;
                for(int j = 0 ; j < m ; j++){
                    hash[t[j]]++;
                }
                for(int  j = i ; j < n ; j++){
                    if(hash[s[j]] > 0) {
                        count  = count+1;
                    }
                      hash[s[j]]--;
                    
    
                    if(count  == m){
                        if(j-i+1 < minlen){
                            minlen = j-i+1;
                            start = i ;
                            
                        }
                        break;
                    }
                }
            }
            return (start == -1) ? "" : s.substr(start, minlen);
            
        }
    };








    class Solution {
        public:
            string minWindow(string s, string t) {
                int n = s.length(), m = t.length();
                int l = 0, r = 0, cnt = 0;
                int maxLen = INT_MAX;
                int sIndex = -1;
                vector<int> hash(256, 0);
        
                for (char c : t) {
                    hash[c]++;
                }
        
                while (r < n) {
                    if (hash[s[r]] > 0) cnt++;
                    hash[s[r]]--;
                    while (cnt == m) {
                        if (r - l + 1 < maxLen) {
                            maxLen = r - l + 1;
                            sIndex = l;
                        }
                        hash[s[l]]++;
                        if (hash[s[l]] > 0) cnt--;
                        l++;
                    }
                    r++;
                }
        
                return maxLen == INT_MAX ? "" : s.substr(sIndex, maxLen);
            }
        };