#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int lsum=0,rsum=0,max_sum=0;
            for(int i=0;i<k;i++){
                lsum+=cardPoints[i];
            }
            max_sum=lsum;
            int n=cardPoints.size();
            int rightidx=n-1;
            for(int i=k-1;i>=0;i--){
                lsum-=cardPoints[i];
                rsum+=cardPoints[rightidx];
                rightidx-=1;
                max_sum=max(max_sum,lsum+rsum);
            }
            return max_sum;
        }
    };

    // just clean and concise version of above code


    #include <bits/stdc++.h>
    using namespace std;
    
    class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int lsum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0); // Sum of first `k` elements
            int max_sum = lsum, n = cardPoints.size();
    
            for (int i = k - 1, rsum = 0; i >= 0; i--) {
                lsum -= cardPoints[i];  // Remove leftmost element
                rsum += cardPoints[n - (k - i)]; // Add rightmost available element
                max_sum = max(max_sum, lsum + rsum);
            }
    
            return max_sum;
        }
    };
    