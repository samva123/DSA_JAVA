#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum == goal) {
                    count++; // Found a valid subarray
                }
                if (sum > goal) {
                    break; // No need to continue (optimization)
                }
            }
        }

        return count;
    }
};





class Solution {
    public:
        int func(vector<int>& nums, int goal) {
        int l = 0, sum = 0, count = 0;
        if (goal < 0) return 0;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
        }
        return count;
}
    
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            return func(nums , goal) - func(nums , goal-1);
            
        }
    };















    class Solution {
        public:
            int numSubarraysWithSum(vector<int>& nums, int goal) {
                int i = 0, j = 0, sum = 0, count = 0, freq = 0;
        
                while (i < nums.size()) {
                    sum += nums[i];
                    if (nums[i] == 1) {
                        freq = 0;
                    }
                    if (sum > goal) {
                        sum -= nums[j];
                        j++;
                    }
                    while (j <= i && sum == goal) {
                        sum -= nums[j];
                        j++;
                        freq++;
                    }
                    count += freq;
                    i++;
                }
                return count;
            }
        };




        





// all three solution is in below link 


// https://leetcode.com/problems/binary-subarrays-with-sum/solutions/4873684/3-approach-all-3-explained-in-depth-java-c-c-python3-javasript-rust-go