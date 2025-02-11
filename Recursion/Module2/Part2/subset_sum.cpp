// sttriver


#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void subsetSumsHelper(int ind, vector < int > & arr, int n, vector < int > & ans, int sum) {
      if (ind == n) {
        ans.push_back(sum);
        return;
      }
      //element is picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum + arr[ind]);
      //element is not picked
      subsetSumsHelper(ind + 1, arr, n, ans, sum);
    }
  vector < int > subsetSums(vector < int > arr, int n) {
    vector < int > ans;
    subsetSumsHelper(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
  }
};


int main() {
  vector < int > arr{3,1,2};
  Solution ob;
  vector < int > ans = ob.subsetSums(arr, arr.size());
  sort(ans.begin(), ans.end());
  cout<<"The sum of each subset is "<<endl;
  for (auto sum: ans) {
    cout << sum << " ";
  }
  cout << endl;

  return 0;
}



// The sum of each subset is
// 0 1 2 3 3 4 5 6

// Time Complexity: O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).

// Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.











// class Solution {
//   public:
//     vector<int> subsetSums(vector<int>& arr) {
//         // code here
//         vector<int> result;
//         int sum = 0;
//         result.push_back(sum);
//         for(int i = 0;i<arr.size();i++){
//             for(int j = 0;j<result.size();j++){
//                 result.push_back(result[j] + arr[i]);
//             }
//         }
//         return result;
//     }
// };




// we can more optimise it by using dp


