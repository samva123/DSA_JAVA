#include<bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
      if (ind == arr.size()) {
        if (target == 0) {
          ans.push_back(ds);
        }
        return;
      }
      // pick up the element 
      if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findCombination(ind, target - arr[ind], arr, ans, ds);
        ds.pop_back();
      }

      findCombination(ind + 1, target, arr, ans, ds);

    }
  public:
    vector < vector < int >> combinationSum(vector < int > & candidates, int target) {
      vector < vector < int >> ans;
      vector < int > ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};
int main() {
  Solution obj;
  vector < int > v {2,3,6,7};
  int target = 7;

  vector < vector < int >> ans = obj.combinationSum(v, target);
  cout << "Combinations are: " << endl;
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
}



// Time Complexity: O(2^t * k) where t is the target, k is the average length

// Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

// Why not (2^n) but (2^t) (where n is the size of an array)?

// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.

// Space Complexity: O(k*x), k is the average length and x is the no. of combinations


















#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        
        for (int i = ind; i < arr.size(); ++i) {
            if (arr[i] > target) break; // Early termination
            ds.push_back(arr[i]);
            findCombination(i, target - arr[i], arr, ans, ds);
            ds.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end()); // Sort the input array
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> v {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (const auto &combination : ans) {
        for (int num : combination)
            cout << num << " ";
        cout << endl;
    }
}



// we can also use continue instead of break but we then do not have to sort and it will save n logn time but this sapproach is 
// still better because it has time (2^m)*k where m <= t





























// brute force 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generateSubsets(int ind, vector<int> &arr, vector<int> &ds, int sum, int target, vector<vector<int>> &ans) {
        if (ind == arr.size()) {
            if (sum == target) {
                ans.push_back(ds); // Store subset if sum matches target
            }
            return;
        }

        // Pick the element
        ds.push_back(arr[ind]);
        generateSubsets(ind + 1, arr, ds, sum + arr[ind], target, ans);
        ds.pop_back(); // Backtrack

        // Do not pick the element
        generateSubsets(ind + 1, arr, ds, sum, target, ans);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        generateSubsets(0, candidates, ds, 0, target, ans);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> ans = obj.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (const auto &vec : ans) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
}


// Time Complexity:
// •	The brute-force approach generates all possible subsets of the input array. For an array of size n, there are 2^n subsets.
// •	For each subset, we calculate the sum, which takes O(n) time.
// •	Therefore, the overall time complexity is O(n⋅2^n).
// Space Complexity:
// •	The space complexity is O(n⋅2^n)to store all valid subsets in the worst case.

