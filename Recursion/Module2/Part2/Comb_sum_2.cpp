// deepseek

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void solve(vector<int>& cand, vector<int>& current,
               vector<vector<int>>& res, int target, int idx) {
        if (target == 0) {
            res.emplace_back(current); // Use emplace_back for efficiency
            return;
        }
        for (int i = idx; i < cand.size(); i++) {
            // Early termination if the current element is greater than the remaining target
            if (cand[i] > target) break;

            // Skip duplicates to avoid redundant combinations
            if (i > idx && cand[i] == cand[i - 1]) continue;

            current.push_back(cand[i]);
            solve(cand, current, res, target - cand[i], i + 1); // Pass remaining target
            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(cand.begin(), cand.end()); // Sort to handle duplicates and early termination
        solve(cand, current, res, target, 0);
        return res;
    }
};

int main() {
    Solution obj;
    vector<int> v {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = obj.combinationSum2(v, target);
    cout << "Combinations are: " << endl;
    for (const auto& combination : ans) {
        for (int num : combination)
            cout << num << " ";
        cout << endl;
    }
}

// Time Complexity:
// •	Sorting: O(nlog⁡n)O(nlogn), where nn is the size of the input array.
// •	Recursion: In the worst case, the recursion explores all possible subsets, which is O(2^n)O(2n).
// •	Overall time complexity: O(nlog⁡n+2^n)O(nlogn+2n).
// ________________________________________
// Space Complexity:
// •	Recursion Stack: The depth of the recursion stack is at most O(n)O(n).
// •	Output Space: The space required to store all valid combinations is O(k⋅m)O(k⋅m), where kk is the number of combinations and mm is the average size of a combination.








// striver





#include<bits/stdc++.h>

using namespace std;
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
int main() {
  vector<int> v{10,1,2,7,6,1,5};
  vector < vector < int >> comb = combinationSum2(v, 8);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}
// Output:

// [ [ 1 1 6 ][ 1 2 5 ][ 1 7 ][ 2 6 ] ]

// Time Complexity:O(2^n*k)

// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.

// Space Complexity:O(k*x)

// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.

















//brute force///////
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void generateSubsets(int ind, vector<int>& candidates, vector<int>& ds, set<vector<int>>& uniqueSubsets, int target) {
        // Base case: if we've processed all elements
        if (ind == candidates.size()) {
            // Check if the current subset sums to the target
            int sum = 0;
            for (int num : ds) {
                sum += num;
            }
            if (sum == target) {
                // Sort the subset to handle duplicates
                vector<int> sortedDs = ds;
                sort(sortedDs.begin(), sortedDs.end());
                uniqueSubsets.insert(sortedDs); // Add to set to avoid duplicates
            }
            return;
        }

        // Include the current element
        ds.push_back(candidates[ind]);
        generateSubsets(ind + 1, candidates, ds, uniqueSubsets, target);
        ds.pop_back(); // Backtrack

        // Exclude the current element
        generateSubsets(ind + 1, candidates, ds, uniqueSubsets, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> uniqueSubsets; // To store unique combinations
        vector<int> ds;
        generateSubsets(0, candidates, ds, uniqueSubsets, target);

        // Convert the set to a vector
        vector<vector<int>> ans(uniqueSubsets.begin(), uniqueSubsets.end());
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> v {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> ans = obj.combinationSum2(v, target);
    cout << "Combinations are: " << endl;
    for (const auto& combination : ans) {
        for (int num : combination)
            cout << num << " ";
        cout << endl;
    }
}



// Time Complexity:
// 1.	Subset Generation:
// o	There are 2n2n possible subsets for an array of size nn.
// 2.	Sum Calculation:
// o	For each subset, calculating the sum takes O(n)O(n) time.
// 3.	Sorting and Set Insertion:
// o	Sorting each subset takes O(nlog⁡n)O(nlogn), and inserting it into the set takes O(log⁡m)O(logm), where mm is the number of unique subsets.
// 4.	Overall Time Complexity:
// o	O(2^n⋅nlog⁡n).
// ________________________________________
// Space Complexity:
// 1.	Recursion Stack:
// o	The recursion depth is O(n)O(n).
// 2.	Set Storage:
// o	The set uniqueSubsets stores all unique subsets, which can be up to O(2n)O(2n) in the worst case.
// 3.	Overall Space Complexity:
// o	O(2n⋅n)O(2n⋅n).

