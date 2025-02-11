#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void insertAtBottom(stack<int> &st, int &element)
    {
        // base case
        if (st.empty())
        {
            st.push(element);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, element);

        st.push(temp);
    }
    void Reverse(stack<int> &st)
    {
        if (st.empty())
        {
            return;
        }
        int temp = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, temp);
    }
};