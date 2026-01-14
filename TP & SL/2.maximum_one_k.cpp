#include<bits/stdc++.h>
using namespace std;



class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int maxlen=0;
            int len = 0 ;
            for(int i=0; i<nums.size(); i++){
                int count=0;
                for(int j=i; j<nums.size(); j++){
                    if(nums[j]==0 ){
                        count++;
                    }
                    if(count <= k ){
                        len = j-i+1;
                        maxlen  = max(len , maxlen);
                    }
                    else
                        break;
                    
                }
            }
            return maxlen;
        }
    };











class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int left = 0, maxLength = 0, zeroCount = 0;
    
            for (int right = 0; right < nums.size(); ++right) {
                if (nums[right] == 0) {
                    zeroCount++;
                }
                while (zeroCount > k) {
                    if (nums[left] == 0) {
                        zeroCount--;
                    }
                    left++;
                }
                maxLength = max(maxLength, right - left + 1);
            }
    
            return maxLength;
        }
    };
















// these approaches are going from brute force to most optimal 

// https://leetcode.com/problems/max-consecutive-ones-iii/solutions/6283022/beats-100-4-solutions

// a solution for refrence if needed