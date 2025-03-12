class Solution {
  public:
      int lengthOfLongestSubstring(string s) {
          int n  = s.size();int len  = 0 ; int maxlen  = 0;
          for(int i = 0; i < n ; i++){
              int hash[256] = {0};
              for(int j = i ; j < n ; j++){
                  if(hash[s[j]] == 1) break;
                  len  = j-i+1;
                  maxlen  = max(len , maxlen);
                  hash[s[j]] = 1;
              }
          }
          return maxlen;
      }
  };














class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int left = 0;
    int maxLength = 0;
    unordered_set<char> charSet;

    for (int right = 0; right < s.length(); right++)
    {
      while (charSet.find(s[right]) != charSet.end())
      {
        charSet.erase(s[left]);
        left++;
      }

      charSet.insert(s[right]);
      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }
};













class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int maxLength = 0;
    int left = 0;
    unordered_map<char, int> lastSeen;

    for (int right = 0; right < s.length(); right++)
    {
      char c = s[right];
      if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left)
      {
        left = lastSeen[c] + 1;
      }
      maxLength = max(maxLength, right - left + 1);
      lastSeen[c] = right;
    }

    return maxLength;
  }
};
















#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
  int lengthofLongestSubstring(string s)
  {
    vector<int> mpp(256, -1);

    int left = 0, right = 0;
    int n = s.size();
    int len = 0;
    while (right < n)
    {
      if (mpp[s[right]] != -1)
        left = max(mpp[s[right]] + 1, left);

      mpp[s[right]] = right;

      len = max(len, right - left + 1);
      right++;
    }
    return len;
  }
};

int main()
{
  string str = "takeUforward";
  Solution obj;
  cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
  return 0;
}