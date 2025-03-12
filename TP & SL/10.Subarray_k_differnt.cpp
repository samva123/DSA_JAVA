#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> distinct; // Track distinct elements
            for (int j = i; j < n; j++) {
                distinct.insert(nums[j]); // Add element to set
                if (distinct.size() == k) {
                    count++; // Valid subarray
                } else if (distinct.size() > k) {
                    break; // No need to continue
                }
            }
        }

        return count;
    }
};










class Solution {
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            int sub_with_max_element_k = subarray_with_atmost_k(nums,k);
            int reduced_sub_with_max_k = subarray_with_atmost_k(nums,k-1);
            return (sub_with_max_element_k - reduced_sub_with_max_k);
        }
        int subarray_with_atmost_k(vector<int>& nums,int k){
            unordered_map<int,int> map;
            int left = 0 , right = 0,ans = 0;
            while(right<nums.size()){
                map[nums[right]]++;
                while(map.size()>k){
                    map[nums[left]]--;
                    if(map[nums[left]]==0)map.erase(nums[left]);
                    left++;
                }
                ans += right-left+1; // basically the size of subarray;
                right++;
            }
            return ans;
        }
    };