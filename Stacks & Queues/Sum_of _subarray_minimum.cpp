#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            if (st.top() == -1)
                ans[i] = n;
            else
                ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    // prev Smaller
    vector<int> prevSmaller(vector<int> &arr, int n)
    {
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {

        int n  = arr.size();
        int ans=0;
        const int MOD=1e9+7;
        vector<int>nsl = nextSmaller(arr,  n);
        vector<int>nsr = prevSmaller(arr,  n);

        for(int i=0;i<n;++i){
            long long l=i-nsl[i];
            long long r=nsr[i]-i;
            long long m=(l%MOD * r%MOD) % MOD;
            ans=(ans + (arr[i] * m) % MOD) % MOD;
        }

        return ans;

        
    }
};